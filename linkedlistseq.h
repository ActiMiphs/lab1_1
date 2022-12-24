#ifndef UNTITLED_LINKEDLISTSEQ_H
#define UNTITLED_LINKEDLISTSEQ_H
#include "linkedlist.h"
#include "sequence.h"

template <class T>
class LinkedListSequence : public Sequence<T>{
private:
    LinkedList<T>* list;
public:
    LinkedListSequence(){
        list = new LinkedList<T>();
    }
    LinkedListSequence(int size){
        list = new LinkedList<T>(size);
    }
    LinkedListSequence(const LinkedListSequence<T>& other){
        list = new LinkedList<T>(other.list->getsize());
        for (int i = 0; i < list->getsize(); i++){
            list->set(i, other.list->get(i));
        }
    }
    ~LinkedListSequence(){
        delete list;
    }
    int getsize(){
        return list->getsize();
    }
    const T& get(int index){
        return list->get(index);
    }
    void set(int index, const T& value){
        list->set(index, value);
    }
    void resize(int newsize){
        list->resize(newsize);
    }
    void append(const T& value){
        list->resize(list->getsize() + 1);
        list->set(list->getsize() - 1, value);
    }
    void prepend(const T& value){
        list->resize(list->getsize() + 1);
        for (int i = list->getsize() - 1; i > 0; i--){
            list->set(i, list->get(i - 1));
        }
        list->set(0, value);
    }
    void insert(int index, const T& value){
        list->resize(list->getsize() + 1);
        for (int i = list->getsize() - 1; i > index; i--){
            list->set(i, list->get(i - 1));
        }
        list->set(index,value);
    }
    void remove(int index){
        for (int i = index; i < list->getsize() - 1; i++){
            list->set(i, list->get(i + 1));
        }
        list->resize(list->getsize() - 1);
    }
    void print(){
        for (int i = 0; i < list->getsize(); i++){
            std::cout << list->get(i) << " ";
        }
        std::cout << std::endl;
    }
    void bubble(bool (*comparator)(const T&, const T&)){
        list->bubble(list->begin(), list->end(), comparator);
    }
    void insertion(bool (*comparator)(const T&, const T&)){
        list->insertion(list->begin(), list->end(), comparator);
    }
    void selection(bool (*comparator)(const T&, const T&)){
        list->selection(list->begin(), list->end(), comparator);
    }
    void quick(bool (*comparator)(const T&, const T&)){
        list->quick(list->begin(), list->end(), comparator);
    }


};













#endif
