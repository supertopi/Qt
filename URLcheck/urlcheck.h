#ifndef URLCHECK_H
#define URLCHECK_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QVector>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QByteArray>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QThread>


namespace Ui {
    class URLcheck;
}

class URLcheck : public QMainWindow {
    Q_OBJECT
public:
    URLcheck(QWidget *parent = 0);
    ~URLcheck();
    void testaaURLit( int method );

public slots:
    void lueHTML( QByteArray* html = 0 );
    void lueURL();
    void finishedSlot( QNetworkReply* reply );
    void finishedSlot2( QNetworkReply* reply );
    void abortTest();

signals:
    void abortNams();

protected:
    void changeEvent(QEvent *e);

private:
    static bool aborted;
    qreal kasitelty;
    Ui::URLcheck *ui;
    QStandardItemModel* malli;
    QVector< QUrl > vURL;
    QNetworkAccessManager* nam;
    QNetworkAccessManager* nam2;
    QStandardItem* temp;
    QFile* tiedosto;
    QStringList sl;
};

#endif // URLCHECK_H
