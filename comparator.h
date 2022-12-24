
#ifndef UNTITLED_COMPARATOR_H
#define UNTITLED_COMPARATOR_H

template <typename T>
bool compare_asc(const T& a, const T& b) {
    return a < b;
}

template <typename T>
bool compare_dsc(const T& a, const T& b) {
    return a > b;
}

#endif
