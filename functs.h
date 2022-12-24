#ifndef UNTITLED_FUNCTS_H
#define UNTITLED_FUNCTS_H
#include "sequence.h"
#include <iostream>
#include <time.h>

template<typename T>
void fill(Sequence<T> *seq, int count) {
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        seq->append(rand() % 2000 - 1000);
    }
}

template<typename T>
void copy(Sequence<T> *seq, Sequence<T> *seq1) {
    for (int i = 0; i < seq->getsize(); i++) {
        seq1->set(i, seq->get(i));
    }
}

int getNumber();

template<typename T>
void shuffle(Sequence<T>*seq){
    srand(time(NULL));
    for (int i = 0; i < seq->getsize(); i++) {
        int index = rand() % seq->getsize();
        T temp = seq->get(i);
        seq->set(i, seq->get(index));
        seq->set(index, temp);
    }
}

//check if sequence sorted ascending or descending or not sorted
template<typename T>
void checkSort(Sequence<T> *seq) {
    bool ascending = true;
    bool descending = true;
    for (int i = 0; i < seq->getsize() - 1; i++) {
        if (seq->get(i) > seq->get(i + 1)) {
            ascending = false;
        }
        if (seq->get(i) < seq->get(i + 1)) {
            descending = false;
        }
    }
    if (ascending) {
        std::cout << "Sequence is sorted ascending" << std::endl;
    } else if (descending) {
        std::cout << "Sequence is sorted descending" << std::endl;
    } else {
        std::cout << "Sequence is not sorted" << std::endl;
    }
}





#endif //UNTITLED_FUNCTS_H
