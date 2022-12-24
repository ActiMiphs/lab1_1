#ifndef UNTITLED_SEQUENCE_H
#define UNTITLED_SEQUENCE_H


template <class T>
class Sequence{
public:
    virtual int getsize() = 0;
    virtual const T& get(int index) = 0;
    virtual void set(int index, const T& value) = 0;
    virtual void resize(int newsize) = 0;
    virtual void append(const T& value) = 0;
    virtual void prepend(const T& value) = 0;
    virtual void insert(int index, const T& value) = 0;
    virtual void remove(int index) = 0;
    virtual void print() = 0;
    virtual ~Sequence() = default;
    virtual void bubble(bool (*comparator)(const T&, const T&)) = 0;
    virtual void quick(bool (*comparator)(const T&, const T&)) = 0;
    virtual void insertion(bool (*comparator)(const T&, const T&)) = 0;
    virtual void selection(bool (*comparator)(const T&, const T&)) = 0;
};
template class Sequence<int>;




#endif
