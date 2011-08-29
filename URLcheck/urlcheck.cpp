#include "urlcheck.h"
#include "ui_urlcheck.h"

bool URLcheck::aborted(false);

URLcheck::URLcheck(QWidget *parent) :
    QMainWindow(parent),kasitelty(0),
    ui(new Ui::URLcheck)
{
    ui->setupUi(this);

    this->ui->progressBar->hide();
    this->ui->progressBar->setRange(0,100);

    nam = new QNetworkAccessManager(this);
    nam->killTimer(15);
    nam2 = new QNetworkAccessManager(this);
    nam->killTimer(15);

    malli = new QStandardItemModel(this);

    sl << "Link URL" << "Response code";
    malli->setColumnCount(2);
    malli->setHorizontalHeaderLabels( sl );


    this->ui->urltable->setModel(malli);
    this->ui->urltable->setColumnWidth(0,355);
    this->ui->urltable->setColumnWidth(1,152);

    connect(this->ui->openButton,SIGNAL(clicked()),this,SLOT(lueHTML()));
    connect(this->ui->urlButton,SIGNAL(clicked()),this,SLOT(lueURL()));

    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(finishedSlot(QNetworkReply*)), Qt::QueuedConnection);
    QObject::connect(nam2, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(finishedSlot2(QNetworkReply*)));
    nam->thread();

}

URLcheck::~URLcheck()
{
    delete ui;
}

void URLcheck::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void URLcheck::lueHTML( QByteArray* html )
{
    aborted = false;
    vURL.clear();
    malli->removeRows(0,malli->rowCount());

    QTextStream* virta;
    if( html == 0)
    {

    tiedosto = new QFile( QFileDialog::getOpenFileName(this,
        tr("HTML tiedosto"), ".", tr("HTML files (*.html *.htm *.xml)")) );
      if( tiedosto->open( QIODevice::ReadOnly ) )
      {
         virta = new QTextStream(tiedosto);
      }
      else
      {
          delete tiedosto;
          return;
      }
    }
    else
    {
        virta = new QTextStream(html);
    }

    kasitelty = 0;
//käsittely
    QString haettava1 = "href=";
    QString haettava2 = "src=";
    QUrl muotoiltu;

    while( !virta->atEnd() )
    {

        QString rivi(virta->readLine());
        QTextStream riviVirta(&rivi);
        QString alkio;
        while( !riviVirta.atEnd())
        {
            riviVirta >> alkio;
            if(alkio.left(5).toLower() == haettava1 )
            {
                muotoiltu = alkio.section('"',1,1);
               if( muotoiltu.toString().left(4) == "http" )
                {
                 vURL.push_back( muotoiltu );
                }

            }
          if( alkio.left(4) == haettava2 )
             {
              muotoiltu = alkio.section('"',1,1);
               if( muotoiltu.toString().left(4) == "http" )
                  {
                vURL.push_back(muotoiltu);
                 }

             }
        }
    }

    testaaURLit( this->ui->methodBox->currentIndex() );
}


void URLcheck::testaaURLit( int method )
{
    this->ui->progressBar->show();
    if( method == 0) //GET
    {
        qDebug() << "getataan";
        for( int i = 0; i != vURL.size() ; ++i )
      {

            nam->get(QNetworkRequest( vURL.at(i) ));
         }
    }
    else //HEAD
    {
        qDebug() << "headataan";
        for( int i = 0; i != vURL.size() ; ++i )
        {
            nam->head(QNetworkRequest( vURL.at(i) ));
        }

    }


}

void URLcheck::finishedSlot( QNetworkReply* reply )
{

    reply->ignoreSslErrors();
    QVariant statusCodeV;
    statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    if( statusCodeV.toString() == "200")
    {
        temp = new QStandardItem();
        temp->setText( reply->url().toString() );
        malli->setItem( malli->rowCount(),0,temp );
        temp = new QStandardItem();
        temp->setText( statusCodeV.toString() + " OK");
        malli->setItem( malli->rowCount()-1,1,temp);

        ++kasitelty;
        qreal kokoDouble = vURL.size();
        qreal luku = kasitelty / kokoDouble;
        this->ui->progressBar->setValue( luku*100 );

    }
    else if( statusCodeV.toString().left(2) == "30" )
    {
        // eriosoitteessa
        if( reply->header(QNetworkRequest::LocationHeader ).toString().length() != 0 )
        { // ohjaus http osoitteeseen
            nam->get(QNetworkRequest( reply->header(QNetworkRequest::LocationHeader ).toUrl() ));
        }
        else
        {//ohjaus tyhjään tai turhaan
            temp = new QStandardItem();
            temp->setText( reply->url().toString() );
            malli->setItem( malli->rowCount(),0,temp );
            temp = new QStandardItem();
            temp->setText("Empty redirect location header: " + statusCodeV.toString()  );
            malli->setItem( malli->rowCount()-1,1,temp);

            ++kasitelty;
            qreal kokoDouble = vURL.size();
            qreal luku = kasitelty / kokoDouble;
            this->ui->progressBar->setValue( luku*100 );

        }

    }
    else if( statusCodeV.toString() == "404")
    {
        temp = new QStandardItem();
        temp->setText( reply->url().toString() );
        malli->setItem( malli->rowCount(),0,temp );

        temp = new QStandardItem();
        temp->setText( statusCodeV.toString() + " Not found" );
        malli->setItem( malli->rowCount()-1,1,temp);

        ++kasitelty;
        qreal kokoDouble = vURL.size();
        qreal luku = kasitelty / kokoDouble;
        this->ui->progressBar->setValue( luku*100 );

    }
    else if( statusCodeV.toString() == "500")
    {
        temp = new QStandardItem();
        temp->setText( reply->url().toString() );
        malli->setItem( malli->rowCount(),0,temp );

        temp = new QStandardItem();
        temp->setText( statusCodeV.toString() + " Server error" );
        malli->setItem( malli->rowCount()-1,1,temp);

        ++kasitelty;
        qreal kokoDouble = vURL.size();
        qreal luku = kasitelty / kokoDouble;
        this->ui->progressBar->setValue( luku*100 );

    }
    else
    {
        QString temppi( reply->url().toString() );
        qDebug() << temppi;
        temp = new QStandardItem();
        temp->setText( reply->url().toString()  );
        malli->setItem( malli->rowCount(),0,temp );

        temp = new QStandardItem();
        temp->setText( statusCodeV.toString() );
        malli->setItem( malli->rowCount()-1,1,temp);

        ++kasitelty;
        qreal kokoDouble = vURL.size();
        qreal luku = kasitelty / kokoDouble;
        this->ui->progressBar->setValue( luku*100 );

    }



}

void URLcheck::finishedSlot2( QNetworkReply* reply )
{
    reply->ignoreSslErrors();
    QVariant statusCodeV;
    statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if( statusCodeV.toString() == "200" )
    {
        QByteArray* array = new QByteArray( reply->readAll() );
        lueHTML( array );
    }
    else if( statusCodeV.toString().left(2) == "30" )
    {
        nam2->get( QNetworkRequest( reply->header(QNetworkRequest::LocationHeader).toUrl() ));
    }

}

void URLcheck::lueURL()
{

    //käsittele invalid url
    QString urlString = this->ui->urlEdit->text();

    if( urlString.left(7) == "http://" )
    {
       nam2->get(QNetworkRequest( urlString ));

    }

}



void URLcheck::abortTest()
{

    aborted = true;
}

