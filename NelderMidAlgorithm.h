#include<iostream>
#include<cstdlib>
#include<ctime>
#include <list>
#include <SElement.h>
#include "SElement.h"

namespace NelderMid{

    std::list<std::shared_ptr<SElement>> *generateArr(int x);
    void start(double(*fu)(double,double));
    bool cycle();
    void sort(std::list<std::shared_ptr<SElement>>& list);

}