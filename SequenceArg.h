//
// Created by bandit on 4/9/16.
//

#ifndef SECOND_SEQUENCEARG_H
#define SECOND_SEQUENCEARG_H


class SequenceArg {
        double x1;
        double x2;
    public:
        SequenceArg(double _x1, double _x2):x1(_x1),x2(_x2){};
        SequenceArg &operator+(SequenceArg &);
        SequenceArg &operator*(double val);
        SequenceArg &operator-(SequenceArg &);
        SequenceArg &operator/(double val);
        double get_first();
        double get_second();

    };



#endif //SECOND_SEQUENCEARG_H
