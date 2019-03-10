#ifndef CALCOLO_H
#define CALCOLO_H
#include <list>
#include "cellainput.h"

class Calcolo
{
public:
    virtual double operazione(std::list<CellaInput*>* listaCelle)=0;
    virtual ~Calcolo(){}
};

#endif // CALCOLO_H
