#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cellaoutput.h"
#include "cellainput.h"
#include <list>
#include <QTableWidgetItem>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow* getUi()const{//per fare i test
        return ui;
    }
    CellaOutput* getCellaSum(){
        return cellaSum;
    }
    CellaOutput* getCellaProd(){
        return cellaProd;
    }
    CellaOutput* getCellaMax(){
        return cellaMax;
    }
    CellaOutput* getCellaMin(){
        return cellaMin;
    }
    CellaOutput* getCellaMed(){
        return cellaMed;
    }
//    QTableWidget* getQTableWidget(){
//        return table;
//    }
    std::list<CellaInput*> getListaCelle(){
        return listaCelleIn;
    }
    void fullAttach(){
        cellaSum->attach();
        cellaProd->attach();
        cellaMax->attach();
        cellaMin->attach();
        cellaMed->attach();
    }

public slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_tableWidget_itemChanged(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
    std::list<CellaInput*> listaCelleIn={};
    CellaOutput *cellaSum;
    CellaOutput *cellaProd;
    CellaOutput *cellaMax;
    CellaOutput *cellaMin;
    CellaOutput *cellaMed;
};


#endif // MAINWINDOW_H
