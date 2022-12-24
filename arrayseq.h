#ifndef UNTITLED_ARRAYSEQ_H
#define UNTITLED_ARRAYSEQ_H
#include "array.h"
#include "sequence.h"

template <class T>
class ArraySequence : public Sequence<T>{
private:
    DynamicArray<T>* arr;
public:
    ArraySequence(){
        arr = new DynamicArray<T>();
    }
    ArraySequence(int size){
        arr = new DynamicArray<T>(size);
    }
    ArraySequence(const ArraySequence<T>& other){
        arr = new DynamicArray<T>(other.arr->getsize());
        for (int i = 0; i < arr->getsize(); i++){
            arr->set(i, other.arr->get(i));
        }
    }
    ~ArraySequence(){
        delete arr;
    }
    int getsize(){
        return arr->getsize();
    }
    const T& get(int index){
        return arr->get(index);
    }
    void set(int index, const T& value){
        arr->set(index, value);
        }
    void resize(int newsize){
        arr->resize(newsize);
    }
    void append(const T& value){
        arr->resize(arr->getsize() + 1);
        arr->set(arr->getsize() - 1, value);
    }
    void prepend(const T& value){
        arr->resize(arr->getsize() + 1);
        for (int i = arr->getsize() - 1; i > 0; i--){
            arr->set(i, arr->get(i - 1));
        }
        arr->set(0, value);
    }
    void insert(int index, const T& value){
        arr->resize(arr->getsize() + 1);
        for (int i = arr->getsize() - 1; i > index; i--){
            arr->set(i, arr->get(i - 1));
        }
        arr->set(index, value);
    }
    void remove(int index){
        for (int i = index; i < arr->getsize() - 1; i++){
            arr->set(i, arr->get(i + 1));
        }
        arr->resize(arr->getsize() - 1);
    }
    void print(){
        for (int i = 0; i < arr->getsize(); i++){
            std::cout << arr->get(i) << " ";
        }
        std::cout << std::endl;
    }

    void bubble(bool (*comparator)(const T&, const T&)){
        arr->bubble(arr->begin(), arr->end(), comparator);
    }
    void insertion(bool (*comparator)(const T&, const T&)){
        arr->insertion(arr->begin(), arr->end(), comparator);
    }
    void selection(bool (*comparator)(const T&, const T&)){
        arr->selection(arr->begin(), arr->end(), comparator);
    }
    void quick(bool (*comparator)(const T&, const T&)){
        arr->quick(arr->begin(), arr->end(), comparator);
    }
};



#endif
