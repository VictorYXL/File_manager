/********************************************************************************
** Form generated from reading UI file 'filemanager.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEMANAGER_H
#define UI_FILEMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileManager
{
public:
    QWidget *centralWidget;
    QListWidget *lwt_File;
    QLabel *lbl_Menu;
    QLineEdit *let_Menu;
    QPushButton *btn_Copy;
    QPushButton *btn_Exit;
    QPushButton *btn_Paste;
    QPushButton *btn_Enter;
    QPushButton *btn_Delete;
    QPushButton *btn_UDisk;
    QPushButton *btn_Cut;
    QPushButton *btn_Root;
    QPushButton *btn_Up;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FileManager)
    {
        if (FileManager->objectName().isEmpty())
            FileManager->setObjectName(QStringLiteral("FileManager"));
        FileManager->resize(802, 480);
        centralWidget = new QWidget(FileManager);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lwt_File = new QListWidget(centralWidget);
        lwt_File->setObjectName(QStringLiteral("lwt_File"));
        lwt_File->setGeometry(QRect(20, 60, 421, 351));
        lbl_Menu = new QLabel(centralWidget);
        lbl_Menu->setObjectName(QStringLiteral("lbl_Menu"));
        lbl_Menu->setGeometry(QRect(20, 10, 81, 41));
        let_Menu = new QLineEdit(centralWidget);
        let_Menu->setObjectName(QStringLiteral("let_Menu"));
        let_Menu->setGeometry(QRect(120, 16, 301, 31));
        btn_Copy = new QPushButton(centralWidget);
        btn_Copy->setObjectName(QStringLiteral("btn_Copy"));
        btn_Copy->setGeometry(QRect(470, 190, 81, 61));
        btn_Exit = new QPushButton(centralWidget);
        btn_Exit->setObjectName(QStringLiteral("btn_Exit"));
        btn_Exit->setGeometry(QRect(690, 300, 81, 61));
        btn_Paste = new QPushButton(centralWidget);
        btn_Paste->setObjectName(QStringLiteral("btn_Paste"));
        btn_Paste->setGeometry(QRect(690, 190, 81, 61));
        btn_Enter = new QPushButton(centralWidget);
        btn_Enter->setObjectName(QStringLiteral("btn_Enter"));
        btn_Enter->setGeometry(QRect(580, 300, 81, 61));
        btn_Delete = new QPushButton(centralWidget);
        btn_Delete->setObjectName(QStringLiteral("btn_Delete"));
        btn_Delete->setGeometry(QRect(470, 300, 81, 61));
        btn_UDisk = new QPushButton(centralWidget);
        btn_UDisk->setObjectName(QStringLiteral("btn_UDisk"));
        btn_UDisk->setGeometry(QRect(690, 80, 81, 61));
        btn_Cut = new QPushButton(centralWidget);
        btn_Cut->setObjectName(QStringLiteral("btn_Cut"));
        btn_Cut->setGeometry(QRect(580, 190, 81, 61));
        btn_Root = new QPushButton(centralWidget);
        btn_Root->setObjectName(QStringLiteral("btn_Root"));
        btn_Root->setGeometry(QRect(470, 80, 81, 61));
        btn_Up = new QPushButton(centralWidget);
        btn_Up->setObjectName(QStringLiteral("btn_Up"));
        btn_Up->setGeometry(QRect(580, 80, 81, 61));
        FileManager->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FileManager);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 802, 26));
        FileManager->setMenuBar(menuBar);
        statusBar = new QStatusBar(FileManager);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FileManager->setStatusBar(statusBar);

        retranslateUi(FileManager);

        QMetaObject::connectSlotsByName(FileManager);
    } // setupUi

    void retranslateUi(QMainWindow *FileManager)
    {
        FileManager->setWindowTitle(QApplication::translate("FileManager", "FileManager", 0));
        lbl_Menu->setText(QApplication::translate("FileManager", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">Menu</span></p></body></html>", 0));
        btn_Copy->setText(QApplication::translate("FileManager", "Copy", 0));
        btn_Exit->setText(QApplication::translate("FileManager", "Exit", 0));
        btn_Paste->setText(QApplication::translate("FileManager", "Paste", 0));
        btn_Enter->setText(QApplication::translate("FileManager", "Enter", 0));
        btn_Delete->setText(QApplication::translate("FileManager", "Delete", 0));
        btn_UDisk->setText(QApplication::translate("FileManager", "UDisk", 0));
        btn_Cut->setText(QApplication::translate("FileManager", "Cut", 0));
        btn_Root->setText(QApplication::translate("FileManager", "Root", 0));
        btn_Up->setText(QApplication::translate("FileManager", "Up", 0));
    } // retranslateUi

};

namespace Ui {
    class FileManager: public Ui_FileManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGER_H
