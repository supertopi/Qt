#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QImage>
#include <QDebug>
#include <QImageReader>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Previkka");

    ristikko = 0;
    kuva = 0;
    rivileveys = 0;
    kolumnileveys = 0;

    connect(this->ui->piirraNappi,SIGNAL(clicked()),this,SLOT(piirraRistikko()));
    connect(this->ui->kuvaNappi,SIGNAL(clicked()),this,SLOT(piirraKuva()));
    connect(this->ui->opaSlider,SIGNAL(valueChanged(int)),this,SLOT(vaihdaOpacity(int)));
    connect(this->ui->piilotaButton,SIGNAL(toggled(bool)),this,SLOT(reunat(bool)));
    connect(this->ui->actionLopeta_2,SIGNAL(triggered()),this,SLOT(close()));

}

MainWindow::~MainWindow()
{
    for(int i = 0; i!=vRistikko.size();++i)
    {
        ristikko = vRistikko.at(i);
        delete ristikko;
    }
    for(int i = 0; i!=vKuva.size();++i)
    {
        kuva = vKuva.at(i);
        delete kuva;
    }
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
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

void MainWindow::piirraRistikko()
{
    QString temp;

    temp = this->ui->rowWidth->text();
    if( temp.length() == 0)
    {
        return;
    }
    for( int i=0;i!=temp.length();++i )
    {
        if( temp.at(i).toAscii() < 48 || temp.at(i).toAscii() > 57 )
        {
            return;
        }
    }
    rivileveys = temp.toInt();

    temp = this->ui->columnWidth->text();
    if( temp.length() == 0)
    {
        return;
    }
    for( int i=0;i!=temp.length();++i )
    {
        if( temp.at(i).toAscii() < 48 || temp.at(i).toAscii() > 57 )
        {
            return;
        }
    }
    kolumnileveys = temp.toInt();



    //väri talteen
    Qt::GlobalColor vari(Qt::black);
    switch( this->ui->variBox->currentIndex() )
    {
    case 0:
        vari = Qt::black;
        break;
    case 1:
        vari = Qt::red;
        break;
    case 2:
        vari = Qt::blue;
        break;
    case 3:
        vari = Qt::green;
        break;
    }

    ristikko = new Ristikko(this, rivileveys,kolumnileveys,vari);
    vRistikko.push_back( ristikko );

}

void MainWindow::piirraKuva()
{

    QString fileFormats = "(";
    /* Get all inputformats */
    for (int i = 0; i < QImageReader::supportedImageFormats().count(); i++) {
            fileFormats += "*."; /* Insert wildcard */
            fileFormats
                            += QString(QImageReader::supportedImageFormats().at(i)).toLower(); /* Insert the format */
            fileFormats += " "; /* Insert a space */
    }
    fileFormats += ")";


    QFile tiedosto( QFileDialog::getOpenFileName(this,
        tr("Kuvatiedosto"), ".", tr( "Kuvatiedostot ") + fileFormats) );
    if( tiedosto.open( QIODevice::ReadOnly ) )
    {
    QPixmap virta(tiedosto.fileName() );
    kuva = new Kuva( this, &virta );
    vKuva.push_back( kuva );
    }

}

void MainWindow::vaihdaOpacity(int arvo)
{
    qreal oikeaArvo = arvo;
    oikeaArvo = oikeaArvo / 100;

    for(int i = 0; i!=vRistikko.size();++i)
    {
        ristikko = vRistikko.at(i);
        if( ristikko != 0)
        {
            ristikko->vaihdaOpacity( oikeaArvo );
        }
    }

    for(int i = 0; i!=vKuva.size();++i)
    {
        kuva = vKuva.at(i);
        if( kuva != 0 )
        {
           kuva->vaihdaOpacity( oikeaArvo );
        }
    }
}

void MainWindow::reunat(bool piiloon)
{
    if(piiloon)
    {
        for(int i = 0; i!=vRistikko.size();++i)
        {
            ristikko = vRistikko.at(i);
            if( ristikko != 0 )
            {
                ristikko->piilotaReunat();
            }
        }

        for(int i = 0; i!=vKuva.size();++i)
        {
            kuva = vKuva.at(i);
            if( kuva != 0 )
            {
               kuva->piilotaReunat();
            }
        }
    }
    else
    {
        for(int i = 0; i!=vRistikko.size();++i)
        {
            ristikko = vRistikko.at(i);
            if( ristikko != 0  )
            {
                ristikko->naytaReunat();
            }
        }

        for(int i = 0; i!=vKuva.size();++i)
        {
            kuva = vKuva.at(i);
            if( kuva != 0  )
            {
               kuva->naytaReunat();
            }
        }
    }
}

void MainWindow::tuhoaKuva()
{
    qDebug() << "tännetuli";
}

void MainWindow::tuhoaRistikko()
{
    qDebug() << "tännetuli";
}
