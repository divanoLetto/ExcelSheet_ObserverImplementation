#ifndef CELLAOUTPUT_H
#define CELLAOUTPUT_H

#include "cellainput.h"
#include "observer.h"
#include <list>
#include <QLineEdit>
#include"calcolo.h"

class CellaOutput:public Observer
{
public:
    CellaOutput(std::list<CellaInput*>* listaCelle,QLineEdit* mySlot,Calcolo* calc):listaCelle(listaCelle), mySlot(mySlot),calc(calc){
        mySlot->setText(QString("%0").arg(0));
    }

    virtual void attach()override{
        if(*(listaCelle->begin())!=*(listaCelle->end())){
            ((listaCelle->back())->registerObserver(this));
        }
    }

    virtual void detach()override{
        for(auto it=listaCelle->begin();it!=listaCelle->end();it++){
            (*it)->removeObserver(this);
        }
    }

    virtual void update()override{
        double result=calc->operazione(listaCelle);
        mySlot->setText(QString("%0").arg(result));
    }
    virtual QLineEdit* getMySlot(){
        return mySlot;
    }
    virtual ~CellaOutput()override{
        if(mySlot!=nullptr){
            delete mySlot;
        }
        delete calc;
    }

private:
    std::list<CellaInput*>* listaCelle;//le due celle che si osservano
    QLineEdit* mySlot;//la cella in cui scrive
    Calcolo* calc;//la specifica dell'operazione che si esegue sulla cella in cui scrive
};

#endif // CELLAOUTPUT_H
