#include "filemanager.h"
#include "ui_filemanager.h"
#include<QDebug>
FileManager::FileManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileManager)
{
    ui->setupUi(this);
    connect(this,SIGNAL(Init()),this,SLOT(Root()));
    connect(ui->lwt_File,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(ItemDoubleClicked(QListWidgetItem*)));
    connect(ui->btn_Root,SIGNAL(clicked()),this,SLOT(Root()));
    connect(ui->btn_UDisk,SIGNAL(clicked()),this,SLOT(UDisk()));
    connect(ui->btn_Copy,SIGNAL(clicked()),this,SLOT(Copy()));
    connect(ui->btn_Cut,SIGNAL(clicked()),this,SLOT(Cut()));
    connect(ui->btn_Paste,SIGNAL(clicked()),this,SLOT(Paste()));
    connect(ui->btn_Delete,SIGNAL(clicked()),this,SLOT(Delete()));
    connect(ui->btn_Enter,SIGNAL(clicked()),this,SLOT(Enter()));
    connect(ui->btn_Up,SIGNAL(clicked()),this,SLOT(Up()));
    connect(ui->btn_Exit,SIGNAL(clicked()),this,SLOT(Exit()));
    UDiskPath=NULL;
    copyFile=NULL;
    copyFlag=0;

    emit Init();
}
FileManager::~FileManager()
{
    delete ui;
}
void FileManager::ShowFile(QDir dir)
{
    ui->lwt_File->clear();
    QFileInfoList fileList=dir.entryInfoList();
    for (int i=0;i<dir.count();i++)
    {
        QIcon icon;
        QListWidgetItem *item=new QListWidgetItem (fileList.at(i).fileName());
        if (fileList.at(i).isDir())
            icon.addFile(QString::fromUtf8(":/Pic/Menu"), QSize(), QIcon::Normal, QIcon::Off);
        else icon.addFile(QString::fromUtf8(":/Pic/File"), QSize(), QIcon::Normal, QIcon::Off);
        item->setIcon(icon);
        ui->lwt_File->addItem(item);
    }
}
void FileManager::ChangePath(QString path)
{
    dir.setPath(path);
    dirPath=dir.absolutePath();
    ui->let_Menu->setText(dir.absolutePath());
}
void FileManager::Go()
{
    QFileInfo file;
    if (ui->let_Menu->text()==dirPath)
    {
        if (ui->lwt_File->selectedItems().count()>0)
            file.setFile(dir,ui->lwt_File->selectedItems().first()->text());
        else file.setFile(dir.dirName());
    }
    else {
        file.setFile(ui->let_Menu->text());
        if (!file.isDir())
            if (ui->lwt_File->selectedItems().count()>0)
                file.setFile(dir,ui->lwt_File->selectedItems().first()->text());
            else file.setFile(dir.dirName());
    }
    if (file.isDir())
    {
        ChangePath(file.filePath());
        ShowFile(dir);
    }
    else {
        ChangePath(file.path());
        ShowFile(dir);
        QProcess *pro=new QProcess();
        qDebug()<<file.filePath();
        pro->start(file.filePath());
        }
}
void FileManager::PasteFile(QString oldFileName, QString newFileName)
{
    QFileInfo file(oldFileName);
    if (file.isDir())
    {
        QDir oldMenu,newMenu;
        oldMenu.setPath(oldFileName);
        newMenu.mkdir(newFileName);
        QFileInfoList fileList=oldMenu.entryInfoList();
        for (int i=2;i<fileList.count();i++)
            PasteFile(oldFileName+"/"+fileList.at(i).fileName(),newFileName+"/"+fileList.at(i).fileName());
    }
    else
        QFile::copy(oldFileName,newFileName);
}
void FileManager::DeleteFile(QString fileName)
{
   QFileInfo file(fileName);
   if (file.isDir())
   {
       QDir fileDir;
       fileDir.setPath(fileName);
       QFileInfoList fileList=fileDir.entryInfoList();
       for (int i=2;i<fileList.count();i++)
           DeleteFile(fileName+"/"+fileList.at(i).fileName());
       fileDir.rmdir(fileName);
   }
   else
       QFile::remove(fileName);
}
void FileManager::Root()
{
    ChangePath("/");
    ShowFile(dir);
}
void FileManager::UDisk()
{
    if (UDiskPath==NULL)
        return;
    ChangePath(*UDiskPath);
    ShowFile(dir);
}
void FileManager::Copy()
{
    GetCopyFile(0);
}
void FileManager::Cut()
{
    GetCopyFile(1);
}
void FileManager::Paste()
{
    if (copyFile->filePath=="/")
        copyFile->filePath="";
    if (dirPath=="/")
        dirPath="";
    PasteFile(copyFile->filePath+"/"+copyFile->fileName,dirPath+"/"+copyFile->fileName);
    if (copyFile->filePath=="")
        copyFile->filePath="/";
    if (dirPath=="")
        dirPath="/";
    dir.setPath(dirPath);
    ShowFile(dir);
}
void FileManager::Delete()
{
    if (ui->lwt_File->selectedItems().count()<=0)
        return;
    if (dirPath=="/")
        dirPath="";
    DeleteFile(dirPath+"/"+ui->lwt_File->selectedItems().first()->text());

    if (dirPath=="")
        dirPath="/";
    dir.setPath(dirPath);
    ShowFile(dir);
}
void FileManager::Enter()
{
    Go();
}
void FileManager::Up()
{
    dir.cd("..");
    ChangePath(dir.path());
    ShowFile(dir);
}
void FileManager::Exit()
{
    exit(0);
}
void FileManager::ItemDoubleClicked(QListWidgetItem*)
{
    Go();
}
void FileManager::GetCopyFile(int function)
{
    if (ui->lwt_File->selectedItems().count()<=0)
        return;
    copyFlag=function;
    copyFile=new CopyFile(dirPath,ui->lwt_File->selectedItems().first()->text());
}
