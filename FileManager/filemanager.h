#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QMainWindow>
#include<QDir>
#include<QListWidget>
#include<QProcess>
namespace Ui {
class FileManager;
}

class FileManager : public QMainWindow
{
    Q_OBJECT
    
public:
    QString dirPath;
    QDir dir;
    QString *UDiskPath;
    struct CopyFile
    {
        CopyFile(QString filePath,QString fileName)
        {
            this->filePath=filePath;
            this->fileName=fileName;
        }
        QString filePath;
        QString fileName;
    }*copyFile;
    bool copyFlag;

    explicit FileManager(QWidget *parent = 0);
    ~FileManager();
    void ShowFile(QDir dir);
    void ChangePath(QString path);
    void Go();
    void GetCopyFile(int function);
    void PasteFile(QString oldFileName,QString newFileName);
    void DeleteFile(QString fileName);
signals:
    void Init();

private:
    Ui::FileManager *ui;

protected slots:
    void Root();
    void UDisk();
    void Copy();
    void Cut();
    void Paste();
    void Delete();
    void Enter();
    void Up();
    void Exit();
    void ItemDoubleClicked(QListWidgetItem*);
};

#endif // FILEMANAGER_H
