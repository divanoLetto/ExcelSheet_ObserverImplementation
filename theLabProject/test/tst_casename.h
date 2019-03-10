#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QApplication>
#include "../labProject/mainwindow.h "
#include <cmath>
#include <stdlib.h>

using namespace testing;

TEST(ini, test1)//primo test
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(ini, test2)//celle input inizializzate correttamente a zero
{
    int c=1;
    char** v = {};
    QApplication app(c,v);
    MainWindow w;
    w.on_pushButton_clicked();
    CellaInput* l=w.getListaCelle().back();
    ASSERT_THAT(l->getItem()->text().toDouble(), 0);
}

TEST(ini, test3)//celle output inizializzate correttamente a zero
{
    int c=1;
    char** v = {};
    QApplication app(c,v);
    MainWindow w;
    EXPECT_EQ((w.getCellaSum()->getMySlot()->text().toDouble()), 0);
    EXPECT_EQ((w.getCellaProd()->getMySlot()->text().toDouble()), 0);
    EXPECT_EQ((w.getCellaMax()->getMySlot()->text().toDouble()), 0);
    EXPECT_EQ((w.getCellaMin()->getMySlot()->text().toDouble()), 0);
    EXPECT_EQ((w.getCellaMed()->getMySlot()->text().toDouble()), 0);
}

TEST(cName, test4)//inserimento di un valore rilevato dagli observer
{
    int c=1;
    char** v = {};
    QApplication app(c,v);
    MainWindow w;

    w.on_pushButton_clicked();//creazione nuova riga
    CellaInput* f=w.getListaCelle().back();
    f->getItem()->setText(QString::number(10));//simula l'inserimento di un valore
    w.on_tableWidget_itemChanged(f->getItem());

    EXPECT_EQ((w.getCellaSum()->getMySlot()->text().toDouble()),10);
    EXPECT_EQ((w.getCellaProd()->getMySlot()->text().toDouble()),10);
    EXPECT_EQ((w.getCellaMax()->getMySlot()->text().toDouble()),10);
    EXPECT_EQ((w.getCellaMin()->getMySlot()->text().toDouble()),10);
    EXPECT_EQ((w.getCellaMed()->getMySlot()->text().toDouble()),10);
}
TEST(cName,test5){//test patter observer su inserimento su cella output cellaSum cellaProd e cellaMedia
    int c=1;
    char** v = {};
    QApplication app(c,v);
    MainWindow w;
    double sum=0;
    double prod=1;
    double media;

    for(int i=1;i<=10;i++){//creo 10 righe
        w.on_pushButton_clicked();//creazione nuova riga
        CellaInput* f=w.getListaCelle().back();
        double num=rand()%10;
        f->getItem()->setText(QString::number(num));//simula l'inserimento di un valore
        w.on_tableWidget_itemChanged(f->getItem());

        sum=sum+num;
        prod=prod*num;
        media=sum/i;

        EXPECT_EQ((w.getCellaSum()->getMySlot()->text().toDouble()), sum);
        EXPECT_EQ((w.getCellaProd()->getMySlot()->text().toDouble()), prod);
        EXPECT_NEAR((w.getCellaMed()->getMySlot()->text().toDouble()), media,0.0005);
    }
}

TEST(cName,test6){//test patter observer su inserimento su cella output cellaMax e cellaMin
    int c=1;
    char** v = {};
    QApplication app(c,v);
    MainWindow w;
    double max;
    double min;

    for(int i=1;i<=10;i++){//creo 10 righe
        w.on_pushButton_clicked();//creazione nuova riga
        CellaInput* f=w.getListaCelle().back();
        double num=rand()%10;
        f->getItem()->setText(QString::number(num));//simula l'inserimento di un valore
        w.on_tableWidget_itemChanged(f->getItem());
        if(i==1){//mi ricordo i valori massimi e minimi per il confronto
            max=num;
            min=num;
        }else{
            if(max<num){
                max=num;
            }
            if(min>num){
                min=num;
            }
        }
        EXPECT_EQ((w.getCellaMax()->getMySlot()->text().toDouble()),max);
        EXPECT_EQ((w.getCellaMin()->getMySlot()->text().toDouble()), min);
    }
}
TEST(cName,test7){//verifica cancellazione righe su cella output cellaMax e cellaMin
    int c=1;
    char** v = {};
    QApplication app(c,v);
    MainWindow w;

    double sum=0;
    double prod=1;
    double media;

    for(int i=1;i<=5;i++){//creo 5 righe
        w.on_pushButton_clicked();//creazione nuova riga
        CellaInput* f=w.getListaCelle().back();
        double num=rand()%10;
        f->getItem()->setText(QString::number(num));//simula l'inserimento di un valore
        w.on_tableWidget_itemChanged(f->getItem());

        sum=sum+num;
        prod=prod*num;
        media=sum/i;

        EXPECT_EQ((w.getCellaSum()->getMySlot()->text().toDouble()), sum);
        EXPECT_EQ((w.getCellaProd()->getMySlot()->text().toDouble()), prod);
        EXPECT_NEAR((w.getCellaMed()->getMySlot()->text().toDouble()), media,0.0005);
    }
    for(int i=1;i<=5;i++){//elimino 5 righe
        CellaInput* f=w.getListaCelle().back();
        double num2=f->getItem()->text().toDouble();

        sum=sum-num2;
        prod=prod/num2;
        media=sum/(5-i);

        w.on_pushButton_2_clicked();//cancellazione ultima riga

        if(i==5){
            EXPECT_EQ((w.getCellaSum()->getMySlot()->text().toDouble()), 0);
            EXPECT_EQ((w.getCellaProd()->getMySlot()->text().toDouble()), 0);
            EXPECT_EQ((w.getCellaMed()->getMySlot()->text().toDouble()),0);
        }
        else{
            w.on_tableWidget_itemChanged(w.getListaCelle().back()->getItem());
            EXPECT_EQ((w.getCellaSum()->getMySlot()->text().toDouble()), sum);
            EXPECT_EQ((w.getCellaProd()->getMySlot()->text().toDouble()), prod);
            EXPECT_NEAR((w.getCellaMed()->getMySlot()->text().toDouble()), media,0.0005);
        }
    }
}
