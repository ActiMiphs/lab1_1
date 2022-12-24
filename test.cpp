#include <iostream>
#include "sequence.h"
#include "arrayseq.h"
#include "linkedlistseq.h"
#include <ctime>
#include "comparator.h"

using namespace std;

void test_append(){
    ArraySequence<int> *arr = new ArraySequence<int>(5);
    LinkedListSequence<int> *list = new LinkedListSequence<int>(5);
    for (int i = 0; i < 5; i++) {
        arr->append(i);
        list->append(i);
    }
    for (int i = 0; i < 5; i++) {
        if (arr->get(i) != list->get(i)) {
            cout << "append test failed" << endl;
            return;
        }
    }
    cout << "append test passed" << endl;
}

void test_prepend(){
    ArraySequence<int> *arr = new ArraySequence<int>(5);
    LinkedListSequence<int> *list = new LinkedListSequence<int>(5);
    for (int i = 0; i < 5; i++) {
        arr->prepend(i);
        list->prepend(i);
    }
    for (int i = 0; i < 5; i++) {
        if (arr->get(i) != list->get(i)) {
            cout << "prepend test failed" << endl;
            return;
        }
    }
    cout << "prepend test passed" << endl;
}

void test_get(){
    ArraySequence<int> *arr = new ArraySequence<int>(5);
    LinkedListSequence<int> *list = new LinkedListSequence<int>(5);
    for (int i = 0; i < 5; i++) {
        arr->set(i, i);
        list->set(i, i);
    }
    for (int i = 0; i < 5; i++) {
        if (arr->get(i) != list->get(i)) {
            cout << "get test failed" << endl;
            return;
        }
    }
    cout << "get test passed" << endl;
}

void test_set(){
    ArraySequence<int> *arr = new ArraySequence<int>(5);
    LinkedListSequence<int> *list = new LinkedListSequence<int>(5);
    for (int i = 0; i < 5; i++) {
        arr->set(i, i);
        list->set(i, i);
    }
    for (int i = 0; i < 5; i++) {
        if (arr->get(i) != list->get(i)) {
            cout << "set test failed" << endl;
            return;
        }
    }
    cout << "set test passed" << endl;
}

void test_resize(){
    ArraySequence<int> *arr = new ArraySequence<int>(5);
    LinkedListSequence<int> *list = new LinkedListSequence<int>(5);
    for (int i = 0; i < 5; i++) {
        arr->set(i, i);
        list->set(i, i);
    }
    arr->resize(10);
    list->resize(10);
    for (int i = 0; i < 5; i++) {
        if (arr->get(i) != list->get(i)) {
            cout << "resize test failed" << endl;
            return;
        }
    }
    cout << "resize test passed" << endl;
}

void test_insert(){
    ArraySequence<int> *arr = new ArraySequence<int>(5);
    LinkedListSequence<int> *list = new LinkedListSequence<int>(5);
    for (int i = 0; i < 5; i++) {
        arr->set(i, i);
        list->set(i, i);
    }
    arr->insert(0, 10);
    list->insert(0, 10);
    for (int i = 0; i < 5; i++) {
        if (arr->get(i) != list->get(i)) {
            cout << "insert test failed" << endl;
            return;
        }
    }
    cout << "insert test passed" << endl;
}

void test_remove(){
    ArraySequence<int> *arr = new ArraySequence<int>(5);
    LinkedListSequence<int> *list = new LinkedListSequence<int>(5);
    for (int i = 0; i < 5; i++) {
        arr->set(i, i);
        list->set(i, i);
    }
    arr->remove(0);
    list->remove(0);
    for (int i = 0; i < 4; i++) {
        if (arr->get(i) != list->get(i)) {
            cout << "remove test failed" << endl;
            return;
        }
    }
    cout << "remove test passed" << endl;
}

void test_getsize(){
    ArraySequence<int> *arr = new ArraySequence<int>(5);
    LinkedListSequence<int> *list = new LinkedListSequence<int>(5);
    for (int i = 0; i < 5; i++) {
        arr->set(i, i);
        list->set(i, i);
    }
    if (arr->getsize() != list->getsize()) {
        cout << "getsize test failed" << endl;
        return;
    }
    cout << "getsize test passed" << endl;
}




void test(){
    srand(time(NULL));
    test_append();
    test_prepend();
    test_get();
    test_set();
    test_resize();
    test_insert();
    test_remove();
    test_getsize();
}



