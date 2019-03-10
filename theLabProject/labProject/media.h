#ifndef MEDIA_H
#define MEDIA_H

#include "calcolo.h"

class Media: public Calcolo{
public:
    Media(){}
    virtual double operazione(std::list<CellaInput*>* listaCelle){
        double sum=0;
        double num=0;
        for(auto it=listaCelle->begin();it!=listaCelle->end();it++){
            sum=sum+(*it)->getItem()->text().toDouble();
            num++;
        }
        return sum/num;
    }

};

#endif // MEDIA_H
