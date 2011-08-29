#include "kuva.h"
#include <QImageReader>
#include <QCloseEvent>

Kuva::Kuva()
{
}

Kuva::Kuva( QWidget* parent, QPixmap* kuva )
    : QWidget(parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose );
    this->setWindowTitle( "Kuva" );

    scene=new QGraphicsScene();
    view = new QGraphicsView();

    QRect ikkuna = QApplication::desktop()->screenGeometry();

    scene->addPixmap( *kuva );

    view->setScene( scene );

    view->setWindowOpacity(0.4);
    view->showNormal();

    this->piilotaReunat();
    this->naytaReunat();

    connect( this, SIGNAL(destroyed()), parent,SLOT(tuhoaKuva()));
    connect( this,SIGNAL(destroyed()),this,SLOT(close()));

}

void Kuva::vaihdaOpacity(qreal arvo)
{
    view->setWindowOpacity( arvo );
}

void Kuva::piilotaReunat()
{
    view->setWindowFlags( Qt::FramelessWindowHint );
    view->show();
}

void Kuva::naytaReunat()
{
    Qt::WindowFlags flags = view->windowFlags();
    flags &= ~Qt::FramelessWindowHint;
    view->setWindowFlags(flags);
    view->show();
}

