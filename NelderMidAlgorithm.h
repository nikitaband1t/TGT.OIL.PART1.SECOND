#include<iostream>
#include<cstdlib>
#include<ctime>
#include <list>
#include "SElement.h"

namespace NelderMid{
    struct pred;
    std::list<std::shared_ptr<SElement>> generateArr(int x);
    void start(double(*fu)(double,double));
    bool cycle(std::list<std::shared_ptr<SElement>>);

    void represent(std::list<std::shared_ptr<SElement>>);
}