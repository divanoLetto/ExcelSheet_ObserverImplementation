#ifndef CELLAINPUT_H
#define CELLAINPUT_H

#include "subject.h"
#include<list>
#include <QString>
#include <QTableWidgetItem>
#include <QMessageBox>//RIMUOVERE

class CellaInput: public Subject
{
public:

    CellaInput(QTableWidgetItem* it){
        item=it;
        list={};
    }
    virtual void registerObserver(Observer*o)override{
        list.push_back(o);
    }
    virtual void removeObserver(Observer*o)override{
        list.remove(o);
    }
    virtual void notifyObserver() const override{
        for(auto itr=list.begin();itr!=list.end();itr++){
            (*itr)->update();
        }
    }
    void textChanged(){
        notifyObserver();
    }  
    QTableWidgetItem* getItem(){
        return item;

    }
    virtual ~CellaInput(){
        if(item!= nullptr){
           delete item;
        }
    }
private:
    QTableWidgetItem* item;
    std::list<Observer*> list;
};

#endif // CELLAINPUT_H
