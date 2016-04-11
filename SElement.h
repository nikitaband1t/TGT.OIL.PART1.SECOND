//
// Created by bandit on 4/9/16.
//

#ifndef SECOND_SELEMENT_H
#define SECOND_SELEMENT_H

#include <bits/shared_ptr.h>
#include "SequenceArg.h"
class SElement {
    double fu;
    std::shared_ptr<SequenceArg> arg;
public:
    SElement(double _x1, double _x2);
    SElement(SequenceArg &arg);
    SequenceArg &get_args();
    void use_func(double (*func)(double, double));
    double get_func_value();



#endif //SECOND_SELEMENT_H
