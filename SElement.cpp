//
// Created by bandit on 4/9/16.
//

#include "SElement.h"
SElement::SElement(double _x1, double _x2):arg(std::shared_ptr<SequenceArg>(new SequenceArg(_x1,_x2))){ }

double SElement::get_func_value() {
    return fu;
}

void SElement::use_func(double (*func)(double, double)) {
    fu = func(arg.get()->get_first(),arg.get()->get_second());
}

SequenceArg &SElement::get_args() {
    return *arg.get();
}