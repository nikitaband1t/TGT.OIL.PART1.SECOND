//
// Created by nikita on 4/9/16.
//

#include <memory>
#include "NelderMidAlgorithm.h"
#include <algorithm>


/**/
std::list<std::shared_ptr<SElement>> NelderMid::generateArr(int x) {
    std::list<std::shared_ptr<SElement>> out_list;
    srand(time(NULL));
    for (int _iterate_ = 0; _iterate_ < x; ++_iterate_) {
        out_list.push_back(std::shared_ptr<SElement>
                                   (new SElement(rand() % 1000 , rand() % 1000)));
    }
    return out_list;
}
/*
 * Comparator between to elemts of generated arr
 * */
struct NelderMid::pred{
    bool operator()(const std::shared_ptr<SElement> a,const std::shared_ptr<SElement> b) {
        return (*a).fu < (*b).fu;
    }

};

/*Start main routine which
 * take on input such function fu
 * and do algorithm*/
void NelderMid::start(double (*fu)(double, double)) {
    const int alpha = 1;
    const double beta = 0.5;
    const int gamma = 2;
    auto simplex = generateArr(3);
    /*1*/
    while (/*9*/cycle(simplex)) {
        for (auto _siterator_ = simplex.begin(); _siterator_ != simplex.end(); ++_siterator_) {
            (*_siterator_).get()->use_func(fu);
        }
        /*2*/
        simplex.sort(pred());
        auto xl = (simplex.begin()),xg = xl++,xh = xg++;
        /*3*/
        SequenceArg  xc = ((*(*(xg))).get_args() + (*xl).get()->get_args())/2;
        /*4*/
        SElement *fr = new SElement(xc*(1+alpha) - (*(*xh)).get_args()*alpha);
        /*5*/
       if(fr->get_func_value() < (*(*xg)).get_func_value()) {
           if (fr->get_func_value() < (*xl).get()->get_func_value()) {
               /*5.1*/
               SElement *fe = new SElement(xc * (1 - gamma) - fr->get_args() * gamma);
               (simplex).pop_back();
               /*5.1.1*/
               if (fe->get_func_value() < fr->get_func_value()) {
                   (simplex).push_back(std::shared_ptr<SElement>(fe));
               }
                   /*5.1.2*/
               else if (fr->get_func_value() < fe->get_func_value()) {
                   (simplex).push_back(std::shared_ptr<SElement>(fr));
               }
           }
               /*5.2*/
           else if ((*(*xl)).get_func_value() < fr->get_func_value()) {
               (simplex).pop_back();
               (simplex).push_back(std::shared_ptr<SElement>(fr));
           }
       }
       else {
           /*5.3*/
           if ((*(*xg)).get_func_value() < fr->get_func_value() &&
                    fr->get_func_value() < (*(*xh)).get_func_value()) {
               SElement *xhh = simplex.end().operator*().get();
               (simplex).pop_back();
               (simplex).push_back(std::shared_ptr<SElement>(fr));
               fr = xhh;
           }
           else if ((*(*xh)).get_func_value() < fr->get_func_value()) {

           }
           SElement *fs = new SElement((*(*xh)).get_args()*beta + xc*(1-beta));
           if(fs->get_func_value() > (*(*xh)).get_func_value()){
               (simplex).pop_back();
               (simplex).push_back(std::shared_ptr<SElement>(fs));
           }
           else{
               (simplex).pop_back();(simplex).pop_back();
               simplex.push_back(std::shared_ptr<SElement>(new SElement((*xl).get()->get_args() + ((*(*xh)).get_args() -(*xl).get()->get_args())/2)));
               simplex.push_back(std::shared_ptr<SElement>(new SElement((*xl).get()->get_args() + ((*(*xg)).get_args() -(*xl).get()->get_args())/2)));
           }
       }
    }
    std::cout<<"Answer is:"<<std::endl;
    std::cout<<(*simplex.begin()).get()->get_args().get_first()<<" "<<(*simplex.begin()).get()->get_args().get_second()<<std::endl;
}


/*Represent function*/
void NelderMid::represent(std::list<std::shared_ptr<SElement>> elem){
    for(auto itt = elem.begin();itt!=elem.end();++itt){
        std::cout<<(*itt).get()->get_func_value()<<std::endl;
    }
}
/*I took approximation 0.0005 to get better result
 * */
bool NelderMid::cycle(std::list<std::shared_ptr<SElement>> arr) {
    for(auto itt = arr.begin();itt!=arr.end();++itt){
        bool executable = true;
        for(auto ittq = arr.begin();ittq!=arr.end();++ittq){
            if(abs((*itt).get()->get_args().get_first()
                - (*ittq).get()->get_args().get_first()) <=0.0005
                && abs((*itt).get()->get_args().get_second()
                       - (*ittq).get()->get_args().get_second()) <=0.0005){
                executable = !executable;
            }
        }
        if(!executable)
            return executable;
    }
    return true;
}




