#ifndef MASSIMO_H
#define MASSIMO_H

#include "calcolo.h"

class Massimo: public Calcolo{
public:
    Massimo(){}
    virtual double operazione(std::list<CellaInput*>* listaCelle){
        double max;
        max=listaCelle->front()->getItem()->text().toDouble();
        for(auto it=listaCelle->begin();it!=listaCelle->end();it++){
            if(max<(*it)->getItem()->text().toDouble()){
                max=(*it)->getItem()->text().toDouble();
            }
        }
        return max;
    }
};

#endif // MASSIMO_H
