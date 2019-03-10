#ifndef PRODOTTO_H
#define PRODOTTO_H

#include "calcolo.h"

class Prodotto: public Calcolo{
public:
    Prodotto(){}
    virtual double operazione(std::list<CellaInput*>* listaCelle){
        double prod=1;
        for(auto it=listaCelle->begin();it!=listaCelle->end();it++){
            prod=prod*(*it)->getItem()->text().toDouble();
        }
        return prod;
    }
};

#endif // PRODOTTO_H
