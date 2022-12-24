#ifndef UNTITLED_ARRAY_H
#define UNTITLED_ARRAY_H

#include <iostream>
template <class T>
class DynamicArray{
private:
    T* arr;
    int size;
public:
    DynamicArray(){
        size = 0;
        arr = new T[size];
    }
    DynamicArray(int size){
        this->size = size;
        arr = new T[size];
    }
    DynamicArray(const DynamicArray<T>& other){
        size = other.size;
        arr = new T[size];
        for (int i = 0; i < size; i++){
            arr[i] = other.arr[i];
        }
    }
    ~DynamicArray(){
        delete[] arr;
    }
    int getsize(){
        return size;
    }
    const T& get(int index){
        return arr[index];
    }
    void set(int index, const T& value){
        arr[index] = value;
    }
    void resize(int newsize){
        T* newarr = new T[newsize];
        for (int i = 0; i < newsize; i++){
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
        size = newsize;
    }
    void append(const T& value){
        resize(size + 1);
        arr[size - 1] = value;
    }
    void prepend(const T& value){
        resize(size + 1);
        for (int i = size - 1; i > 0; i--){
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
    }
    void insertAt(int index, const T& value){
        resize(size + 1);
        for (int i = size - 1; i > index; i--){
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
    }
    void removeAt(int index){
        for (int i = index; i < size - 1; i++){
            arr[i] = arr[i + 1];
        }
        resize(size - 1);
    }
    void print(){
        for (int i = 0; i < size; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    class Iterator{
        friend class DynamicArray;
    private:
        T* ptr;
    public:
        Iterator(T* ptr){
            this->ptr = ptr;
        }
        Iterator& operator++(){
            ptr++;
            return *this;
        }
        Iterator& operator--(){
            ptr--;
            return *this;
        }
        Iterator operator++(int){
            Iterator tmp = *this;
            ptr++;
            return tmp;
        }
        Iterator operator--(int){
            Iterator tmp = *this;
            ptr--;
            return tmp;
        }
        T& operator*(){
            return *ptr;
        }
        bool operator==(const Iterator& other){
            return ptr == other.ptr;
        }
        bool operator!=(const Iterator& other){
            return ptr != other.ptr;
        }
        Iterator operator +(int n){
            Iterator tmp = *this;
            tmp.ptr += n;
            return tmp;
        }
        Iterator operator -(int n){
            Iterator tmp = *this;
            tmp.ptr -= n;
            return tmp;
        }
        bool operator >=(const Iterator& other){
            return ptr >= other.ptr;
        }
        bool operator <=(const Iterator& other){
            return ptr <= other.ptr;
        }
        bool operator >(const Iterator& other){
            return ptr > other.ptr;
        }
        bool operator <(const Iterator& other){
            return ptr < other.ptr;
        }
        Iterator operator +(const Iterator& other){
            Iterator tmp = *this;
            tmp.ptr += other.ptr;
            return tmp;
        }
        Iterator operator -(const Iterator& other){
            Iterator tmp = *this;
            tmp.ptr -= other.ptr;
            return tmp;
        }
        Iterator operator /(int n){
            Iterator tmp = *this;
            tmp.ptr /= n;
            return tmp;
        }
        Iterator operator -=(int n){
            ptr -= n;
            return *this;
        }


    };
    Iterator begin(){
        return Iterator(arr);
    }
    Iterator end(){
        return Iterator(arr + (size-1));
    }

    //Bubble sort with iterator and comparator
    void bubble(Iterator begin, Iterator end, bool (*comparator)(const T&, const T&)){
        for (Iterator i = begin; i != end; i++){
            for (Iterator j = begin; j != end; j++){
                if (!comparator(*j, *(j + 1))){
                    T tmp = *j;
                    *j = *(j + 1);
                    *(j + 1) = tmp;
                }
            }
        }
    }

    void quick(Iterator begin, Iterator end, bool (*comparator)(const T&, const T&)){
        if (begin < end){
            Iterator pivot = begin;
            Iterator i = begin + 1;
            Iterator j = end;
            while (i < j){
                while (comparator(*i, *pivot)){
                    i++;
                }
                while (comparator(*pivot, *j)){
                    j--;
                }
                if (i < j){
                    T tmp = *i;
                    *i = *j;
                    *j = tmp;
                }
            }
            T tmp = *pivot;
            *pivot = *j;
            *j = tmp;
            quick(begin, j - 1, comparator);
            quick(j + 1, end, comparator);
        }
    }

    void insertion(Iterator begin, Iterator end, bool (*comparator)(const T&, const T&)){
        for (Iterator i = begin + 1; i <= end; i++){
            T tmp = *i;
            Iterator j = i;
            while (j > begin && !comparator(*(j - 1), tmp)){
                *j = *(j - 1);
                j--;
            }
            *j = tmp;
        }
    }

    void selection(Iterator begin, Iterator end, bool (*comparator)(const T&, const T&)){
        for (Iterator i = begin; i != end; i++){
            Iterator min = i;
            for (Iterator j = i + 1; j <= end; j++){
                if (!comparator(*min, *j)){
                    min = j;
                }
            }
            T tmp = *min;
            *min = *i;
            *i = tmp;
        }
    }




};











#endif
