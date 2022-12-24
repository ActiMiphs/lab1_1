#ifndef UNTITLED_ISORTER_H
#define UNTITLED_ISORTER_H
#include "sequence.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

template <class T>
class ISorter{
public:
    void quick(Sequence<T>*seq, bool (*comparator)(const T&, const T&)){
        high_resolution_clock::time_point t_start, t_end;
        duration<double> time;
        before(seq);
        t_start = high_resolution_clock::now();
        seq->quick(comparator);
        t_end = high_resolution_clock::now();
        time = duration_cast<duration<double>>(t_end - t_start);
        after(seq);
        cout << "time: " << time.count() << endl;
    }
    void bubble(Sequence<T>*seq, bool (*comparator)(const T&, const T&)){
        high_resolution_clock::time_point t_start, t_end;
        duration<double> time;
        before(seq);
        t_start = high_resolution_clock::now();
        seq->bubble(comparator);
        t_end = high_resolution_clock::now();
        time = duration_cast<duration<double>>(t_end - t_start);
        after(seq);
        cout << "time: " << time.count() << endl;
    }
    void insertion(Sequence<T>*seq, bool (*comparator)(const T&, const T&)){
        high_resolution_clock::time_point t_start, t_end;
        duration<double> time;
        before(seq);
        t_start = high_resolution_clock::now();
        seq->insertion(comparator);
        t_end = high_resolution_clock::now();
        time = duration_cast<duration<double>>(t_end - t_start);
        after(seq);
        cout << "time: " << time.count() << endl;
    }
    void selection(Sequence<T>*seq, bool (*comparator)(const T&, const T&)){
        high_resolution_clock::time_point t_start, t_end;
        duration<double> time;
        before(seq);
        t_start = high_resolution_clock::now();
        seq->selection(comparator);
        t_end = high_resolution_clock::now();
        time = duration_cast<duration<double>>(t_end - t_start);
        after(seq);
        cout << "time: " << time.count() << endl;
    }
    void before(Sequence<T>*seq){
        cout << "Before sorting: "<<endl;
        seq->print();
        cout<<endl;
    }
    void after(Sequence<T>*seq){
        cout << "After sorting: "<<endl;
        seq->print();
        cout<<endl;
    }


};









#endif //UNTITLED_ISORTER_H
