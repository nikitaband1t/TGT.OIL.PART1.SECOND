//
// Created by bandit on 4/9/16.
//

#include <bits/shared_ptr.h>
#include "NelderMidAlgorithm.h"

std::list<std::shared_ptr<SElement>> *NelderMid::generateArr(int x) {
    std::list<std::shared_ptr<SElement>> out_list;
    srand(time(NULL));
    for (int _iterate_ = 0; _iterate_ < x; ++_iterate_) {
        out_list.push_back(std::shared_ptr<SElement>
                                   (new SElement(rand() % 1000, rand() % 1000)));
    }
    return &out_list;
}

void NelderMid::start(double (*fu)(double, double)) {
    const int alpha = 1;
    const double beta = 0.5;
    const int gamma = 2;
    auto simplex = generateArr(3);
    while (cycle()) {
        /*1/
        for (auto _siterator_ = simplex->begin(); _siterator_ != simplex->end(); ++_siterator_) {
            (*_siterator_).get()->use_func(fu);
        }
        /*2*/
        sort(*simplex);
        auto xl = (simplex->begin()),xg = xl++,xh = xg++;
        /*3*/
        SequenceArg  xc = ((*(*(xg))).get_args() + (*xl).get()->get_args())/2;
        /*4*/
        SElement *fr = new SElement(xc*(1+alpha) - (*(*xh)).get_args()*alpha);
        /*5*/
       if(fr->get_func_value() < (*(*xg)).get_func_value()) {
           if (fr->get_func_value() < (*xl).get()->get_func_value()) {
               /*5.1*/
               SElement *fe = new SElement(xc * (1 - gamma) - fr->get_args() * gamma);
               (*simplex).pop_back();
               /*5.1.1*/
               if (fe->get_func_value() < fr->get_func_value()) {
                   (*simplex).push_back(fe);
               }
                   /*5.1.2*/
               else if (fr->get_func_value() < fe->get_func_value()) {
                   (*simplex).push_back(fr);
               }
           }
               /*5.2*/
           else if ((*(*xl)).get_func_value() < fr->get_func_value()) {
               (*simplex).pop_back();
               (*simplex).push_back(fr);
           }
       }
       else {
           /*5.3*/
           if ((*(*xg)).get_func_value() < fr->get_func_value() &&
                    fr->get_func_value() < (*(*xh)).get_func_value()) {
               SElement *xhh = std::shared_ptr<SElement>(*(*simplex).end()).get();
               (*simplex).pop_back();
               (*simplex).push_back(fr);
               fr = xhh;
           }
           else if ((*(*xh)).get_func_value() < fr->get_func_value()) {

           }
           SElement *fs = new SElement((*(*xh)).get_args()*beta + xc*(1-beta));
           if(fs->get_func_value() > (*(*xh)).get_func_value()){
               (*simplex).pop_back();
               (*simplex).push_back(fs);
           }
           else{
               (*simplex).pop_back();(*simplex).pop_back();
               simplex->push_back(new SElement((*xl).get()->get_args() + ((*(*xh)).get_args() -(*xl).get()->get_args())/2));
               simplex->push_back(new SElement((*xl).get()->get_args() + ((*(*xg)).get_args() -(*xl).get()->get_args())/2));
           }
       }
    }
}

void NelderMid::sort(std::list<std::shared_ptr<SElement>> &list) {
    for (auto _miterator_ = list.begin(); _miterator_ != list.end(); ++_miterator_) {
        auto replacemnet = list.rbegin() - (std::reverse_iterator) _miterator_;
        auto replace = _miterator_;
        for (auto _iiterator_ = _miterator_; _iiterator_ != list.end(); ++_iiterator_) {
            if ((*_miterator_).get()->get_func_value() < (*_iiterator_).get()->get_func_value()) {
                replace = _iiterator_;
            }
            std::swap(replacemnet, replace);
        }
    }
}

