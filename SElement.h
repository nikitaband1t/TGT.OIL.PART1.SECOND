//
// Created by bandit on 4/9/16.
//

#ifndef SECOND_SELEMENT_H
#define SECOND_SELEMENT_H

#include <memory>
#include "SequenceArg.h"

/*Element of function operation defined simpler
 * methods*/
class SElement {

    std::shared_ptr<SequenceArg> arg;
public:
    double fu;

    SElement(double _x1, double _x2);

    SElement(SequenceArg &arg);

    SequenceArg &get_args();

    void use_func(double (*func)(double, double));

    double get_func_value();

    bool operator<(SElement &);
};

#endif //SECOND_SELEMENT_H
