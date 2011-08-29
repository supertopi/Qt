#ifndef KUVA_H
#define KUVA_H

#include <QtCore>
#include <QWidget>
#include <QWidget>
#include <QDebug>
#include <QLineF>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGLWidget>
#include <QApplication>
#include <QDesktopWidget>

class Kuva : public QWidget
{
public:
    Kuva();
    Kuva( QWidget* parent,  QPixmap* kuva);
    void vaihdaOpacity( qreal arvo );
    void piilotaReunat();
    void naytaReunat();

private:
    QGraphicsView* view;
    QGraphicsScene* scene;
};

#endif // KUVA_H
