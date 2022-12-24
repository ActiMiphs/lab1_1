#include "timer.h"
#include "sequence.h"
#include "arrayseq.h"
#include <iostream>
#include <chrono>
#include "functs.h"
#include "comparator.h"

using namespace std::chrono;


double time_quick(Sequence<int> *seq, bool (*comparator)(const int &, const int &)) {
    high_resolution_clock::time_point t_start, t_end;
    duration<double> time;
    t_start = high_resolution_clock::now();
    seq->quick(comparator);
    t_end = high_resolution_clock::now();
    time = duration_cast<duration<double>>(t_end - t_start);
    return time.count();
}

double time_bubble(Sequence<int> *seq, bool (*comparator)(const int &, const int &)) {
    high_resolution_clock::time_point t_start, t_end;
    duration<double> time;
    t_start = high_resolution_clock::now();
    seq->bubble(comparator);
    t_end = high_resolution_clock::now();
    time = duration_cast<duration<double>>(t_end - t_start);
    return time.count();
}

double time_insertion(Sequence<int> *seq, bool (*comparator)(const int &, const int &)) {
    high_resolution_clock::time_point t_start, t_end;
    duration<double> time;
    t_start = high_resolution_clock::now();
    seq->insertion(comparator);
    t_end = high_resolution_clock::now();
    time = duration_cast<duration<double>>(t_end - t_start);
    return time.count();
}

double time_selection(Sequence<int> *seq, bool (*comparator)(const int &, const int &)) {
    high_resolution_clock::time_point t_start, t_end;
    duration<double> time;
    t_start = high_resolution_clock::now();
    seq->selection(comparator);
    t_end = high_resolution_clock::now();
    time = duration_cast<duration<double>>(t_end - t_start);
    return time.count();
}

void timing(int count){
    std::cout<<"For "<<count<<" elements:"<<std::endl;
    Sequence<int> *seq = new ArraySequence<int>();
    Sequence<int> *seq1 = new ArraySequence<int>(count);
    fill(seq, count);
    copy(seq, seq1);
    std::cout << "Bubble sort: " << time_bubble(seq,compare_asc) << std::endl;
    delete seq;
    seq = new ArraySequence<int>(count);
    copy(seq1, seq);
    std::cout << "Insertion sort: " << time_insertion(seq,compare_asc) << std::endl;
    delete seq;
    seq = new ArraySequence<int>(count);
    copy(seq1, seq);
    std::cout << "Selection sort: " << time_selection(seq,compare_asc) << std::endl;
    delete seq;
    seq = new ArraySequence<int>(count);
    copy(seq1, seq);
    std::cout << "Quick sort: " << time_quick(seq,compare_asc) << std::endl;
    delete seq;
    delete seq1;
}


