#ifndef SUBJECT_H
#define SUBJECT_H

#import "observer.h"

class Subject
{
public:
    virtual void registerObserver(Observer * o) =0;
    virtual void removeObserver(Observer*o) =0;
    virtual void notifyObserver() const=0;
    virtual ~Subject(){}
};

#endif // SUBJECT_H
