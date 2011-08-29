/********************************************************************************
** Form generated from reading UI file 'urlcheck.ui'
**
** Created: Thu 4. Aug 03:02:28 2011
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_URLCHECK_H
#define UI_URLCHECK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_URLcheck
{
public:
    QWidget *centralWidget;
    QPushButton *openButton;
    QTableView *urltable;
    QPushButton *urlButton;
    QLineEdit *urlEdit;
    QLabel *urlLabel;
    QLabel *aboutLabel;
    QLabel *aboutLabel2;
    QLabel *aboutLabel3;
    QProgressBar *progressBar;
    QComboBox *methodBox;
    QLabel *methodLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *URLcheck)
    {
        if (URLcheck->objectName().isEmpty())
            URLcheck->setObjectName(QString::fromUtf8("URLcheck"));
        URLcheck->resize(742, 441);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(URLcheck->sizePolicy().hasHeightForWidth());
        URLcheck->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(URLcheck);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(610, 280, 111, 31));
        urltable = new QTableView(centralWidget);
        urltable->setObjectName(QString::fromUtf8("urltable"));
        urltable->setGeometry(QRect(10, 20, 511, 361));
        urltable->verticalHeader()->setVisible(false);
        urlButton = new QPushButton(centralWidget);
        urlButton->setObjectName(QString::fromUtf8("urlButton"));
        urlButton->setGeometry(QRect(610, 240, 111, 31));
        urlEdit = new QLineEdit(centralWidget);
        urlEdit->setObjectName(QString::fromUtf8("urlEdit"));
        urlEdit->setGeometry(QRect(550, 210, 171, 21));
        urlLabel = new QLabel(centralWidget);
        urlLabel->setObjectName(QString::fromUtf8("urlLabel"));
        urlLabel->setGeometry(QRect(550, 190, 46, 13));
        aboutLabel = new QLabel(centralWidget);
        aboutLabel->setObjectName(QString::fromUtf8("aboutLabel"));
        aboutLabel->setGeometry(QRect(530, 30, 181, 21));
        aboutLabel2 = new QLabel(centralWidget);
        aboutLabel2->setObjectName(QString::fromUtf8("aboutLabel2"));
        aboutLabel2->setGeometry(QRect(530, 50, 201, 20));
        aboutLabel3 = new QLabel(centralWidget);
        aboutLabel3->setObjectName(QString::fromUtf8("aboutLabel3"));
        aboutLabel3->setGeometry(QRect(530, 70, 191, 16));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(580, 150, 118, 23));
        progressBar->setValue(0);
        methodBox = new QComboBox(centralWidget);
        methodBox->setObjectName(QString::fromUtf8("methodBox"));
        methodBox->setGeometry(QRect(640, 330, 74, 22));
        methodLabel = new QLabel(centralWidget);
        methodLabel->setObjectName(QString::fromUtf8("methodLabel"));
        methodLabel->setGeometry(QRect(530, 330, 101, 16));
        URLcheck->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(URLcheck);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 742, 18));
        URLcheck->setMenuBar(menuBar);
        mainToolBar = new QToolBar(URLcheck);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        URLcheck->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(URLcheck);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        URLcheck->setStatusBar(statusBar);

        retranslateUi(URLcheck);

        QMetaObject::connectSlotsByName(URLcheck);
    } // setupUi

    void retranslateUi(QMainWindow *URLcheck)
    {
        URLcheck->setWindowTitle(QApplication::translate("URLcheck", "URLcheck", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("URLcheck", "Avaa tiedosto", 0, QApplication::UnicodeUTF8));
        urltable->setProperty("asd", QVariant(QString()));
        urlButton->setText(QApplication::translate("URLcheck", "Avaa Url", 0, QApplication::UnicodeUTF8));
        urlEdit->setText(QApplication::translate("URLcheck", "http://", 0, QApplication::UnicodeUTF8));
        urlLabel->setText(QApplication::translate("URLcheck", "URL:", 0, QApplication::UnicodeUTF8));
        aboutLabel->setText(QApplication::translate("URLcheck", "About:", 0, QApplication::UnicodeUTF8));
        aboutLabel2->setText(QApplication::translate("URLcheck", "Tarkastaa annetun hyperteksti tiedoston", 0, QApplication::UnicodeUTF8));
        aboutLabel3->setText(QApplication::translate("URLcheck", "tai osoitteen sis\303\244lt\303\244m\303\244t http-linkit.", 0, QApplication::UnicodeUTF8));
        methodBox->clear();
        methodBox->insertItems(0, QStringList()
         << QApplication::translate("URLcheck", "GET", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("URLcheck", "HEAD", 0, QApplication::UnicodeUTF8)
        );
        methodLabel->setText(QApplication::translate("URLcheck", "HTTP-pyynt\303\266metodi", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class URLcheck: public Ui_URLcheck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_URLCHECK_H
