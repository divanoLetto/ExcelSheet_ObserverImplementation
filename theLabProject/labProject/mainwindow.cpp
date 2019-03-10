#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sommatoria.h"
#include "prodotto.h"
#include "massimo.h"
#include "minimo.h"
#include "media.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    Calcolo* calcSum=new Sommatoria();
    cellaSum = new CellaOutput(&listaCelleIn,ui->lineEdit_1,calcSum);
    Calcolo* calcProd=new Prodotto();
    cellaProd=new CellaOutput(&listaCelleIn,ui->lineEdit_3,calcProd);
    Calcolo* calcMax=new Massimo();
    cellaMax = new CellaOutput(&listaCelleIn,ui->lineEdit_2,calcMax);
    Calcolo* calcMin=new Minimo();
    cellaMin = new CellaOutput(&listaCelleIn,ui->lineEdit_5,calcMin);
    Calcolo* calcMedia=new Media();
    cellaMed = new CellaOutput(&listaCelleIn,ui->lineEdit_4,calcMedia);
}

MainWindow::~MainWindow()
{

    delete cellaSum;
    delete cellaProd;
    delete cellaMax;
    delete cellaMin;
    delete cellaMed;
    if(!listaCelleIn.empty()){
        for(auto t : listaCelleIn){
            delete t;
        }
    }
    delete ui;

}

void MainWindow::on_pushButton_clicked()//aggiungi riga
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());//creazione nuova riga

    QTableWidgetItem* it= new QTableWidgetItem(QString::number(0));//creazione item
    CellaInput* c=new CellaInput(it);//cella che mi rappresenta la riga
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,it);//inserimento item nella tabella come ultimo elemento
    listaCelleIn.push_back(c);

    fullAttach();//tutti gli observer si attacano alla nuova cella
    c->textChanged();//notifica iniziale
}

void MainWindow::on_pushButton_2_clicked()//delete riga
{
    if(!listaCelleIn.empty()){

        CellaInput* c=listaCelleIn.back();
        int numColumn=ui->tableWidget->rowCount()-1;

        if(listaCelleIn.front()==listaCelleIn.back()){//un solo elemento rimasto
            ui->tableWidget->item(numColumn,0)->setText(QString::number(0));//pongo a 0 il valore della riga da cancellare
            c->textChanged();//ultima riga notifica di essere cancellata
        }
        listaCelleIn.remove(c);
        ui->tableWidget->removeRow(numColumn);

        if(!listaCelleIn.empty()){//più di un elemento rimasto
            listaCelleIn.back()->textChanged();
        }
    }
}

void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    for( CellaInput* c: listaCelleIn){
        if(c->getItem()==item){
            c->textChanged();
        }
    }
}
