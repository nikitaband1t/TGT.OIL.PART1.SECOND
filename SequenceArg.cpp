//
// Created by bandit on 4/9/16.
//

#include "SequenceArg.h"
SequenceArg  &SequenceArg::operator*(double val) {
     return *(new SequenceArg(x1*val,x2*val));
}

SequenceArg &SequenceArg::operator+(SequenceArg & attr) {
    return *(new SequenceArg(x1+attr.x1,x2+attr.x2));
}

SequenceArg &SequenceArg::operator-(SequenceArg & attr) {
    return *(new SequenceArg(x1-attr.x1,x2-attr.x2));
}

SequenceArg &SequenceArg::operator/(double val) {
    return *(new SequenceArg(x1/val,x2/val));
}