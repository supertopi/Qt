#include "ristikko.h"

Ristikko::Ristikko()
{
}


Ristikko::Ristikko( QWidget* parent, int rh, int cw, Qt::GlobalColor vari )
    :  QWidget(parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose );
    this->setWindowTitle("Ristikko");

    QGraphicsScene* scene=new QGraphicsScene(); 
    view = new QGraphicsView();

    pen = new QPen();
    pen->setColor( vari );
    QRect ikkuna = QApplication::desktop()->screenGeometry();
    

    scene->addText( "^" );


    //vaakaan
    for( int i = 0; i!=(ikkuna.right()/rh) ;++i)
    {

        scene->addLine(0,i*rh, ikkuna.right(),i*rh,*pen);

    }

    //pystyyn
    for( int i = 0; i!=(ikkuna.bottomRight().x() /cw);++i)
    {

         scene->addLine(i*cw, 0, i*cw, ikkuna.bottom(),*pen);
    }

    view->setScene( scene );


    view->setWindowOpacity(0.4);
    view->showNormal();

    this->piilotaReunat();
    this->naytaReunat();

    connect( this, SIGNAL(destroyed()),parent,SLOT(deleteLater()));
    connect( this, SIGNAL(destroyed()), parent,SLOT(tuhoaRistikko()) );

}

void Ristikko::vaihdaOpacity(qreal arvo)
{
    view->setWindowOpacity( arvo );
}

void Ristikko::piilotaReunat()
{
    view->setWindowFlags(Qt::FramelessWindowHint);
    view->show();
}

void Ristikko::naytaReunat()
{
    Qt::WindowFlags flags = view->windowFlags();
    flags &= ~Qt::FramelessWindowHint;
    view->setWindowFlags(flags);
    view->show();
}
