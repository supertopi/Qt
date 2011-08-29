#ifndef RISTIKKO_H
#define RISTIKKO_H

#include <QWidget>
#include <QDebug>
#include <QLineF>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QDesktopWidget>
#include <QPen>
#include <QGraphicsWidget>

class Ristikko : public QWidget
{
public:
    Ristikko();
    Ristikko(  QWidget* parent, int rh,  int cw, Qt::GlobalColor vari);
    void vaihdaOpacity( qreal arvo );
    void piilotaReunat();
    void naytaReunat();

private:
    QGraphicsView* view;
    QPen* pen;

};

#endif // RISTIKKO_H
