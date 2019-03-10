#ifndef OBSERVER_H
#define OBSERVER_H
#include"subject.h"
#include"cellainput.h"

class Observer
{
public:
    virtual void attach()=0;
    virtual void detach()=0;
    virtual void update()=0;
    virtual ~Observer(){}
};

#endif // OBSERVER_H
