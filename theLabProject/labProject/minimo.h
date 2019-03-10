#ifndef MINIMO_H
#define MINIMO_H

#include "calcolo.h"

class Minimo: public Calcolo{
public:
    Minimo(){}
    virtual double operazione(std::list<CellaInput*>* listaCelle){
        double min=listaCelle->front()->getItem()->text().toDouble();;
        for(auto it=listaCelle->begin();it!=listaCelle->end();it++){
            if(min>(*it)->getItem()->text().toDouble()){
                min=(*it)->getItem()->text().toDouble();
            }
        }
        return min;
    }
};


#endif // MINIMO_H
