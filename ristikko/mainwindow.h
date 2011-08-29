#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QVector>

#include "ristikko.h"
#include "kuva.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void piirraRistikko();
    void piirraKuva();
    void vaihdaOpacity(int arvo);
    void reunat( bool piiloon );
    void tuhoaKuva();
    void tuhoaRistikko();
protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    int rivileveys;
    int kolumnileveys;


    Ristikko* ristikko;
    Kuva* kuva;

    QVector< Ristikko* > vRistikko;
    QVector< Kuva* > vKuva;
};

#endif // MAINWINDOW_H
