#ifndef SOMMATORIA_H
#define SOMMATORIA_H

#include "calcolo.h"

class Sommatoria: public Calcolo{
public:
    Sommatoria(){}
    virtual double operazione(std::list<CellaInput*>* listaCelle){
        double sum=0;
        for(auto it=listaCelle->begin();it!=listaCelle->end();it++){
            sum=sum+(*it)->getItem()->text().toDouble();
        }
        return sum;
    }

};
#endif // SOMMATORIA_H
