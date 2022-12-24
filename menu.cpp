//
// Created by Karennn on 24.12.2022.
//

#include "menu.h"
#include <iostream>
#include "functs.h"

int menu_sort() {
    int choice;
    std::cout << "Choose sorting algorithm:" << std::endl;
    do {
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Quick sort" << std::endl;
    std::cout << "2. Bubble sort" << std::endl;
    std::cout << "3. Insertion sort" << std::endl;
    std::cout << "4. Selection sort" << std::endl;
    choice = getNumber();
    }while(choice < 0 || choice > 4);
    return choice;
}

int menu_order(){
    int choice;
    std::cout << "Choose order:" << std::endl;
    do {
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Ascending" << std::endl;
    std::cout << "2. Descending" << std::endl;
    choice = getNumber();
    }while(choice < 0 || choice > 2);
    return choice;
}

int menu_type(){
    int choice;
    std::cout << "Choose type:" << std::endl;
    do {
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Array" << std::endl;
    std::cout << "2. Linked list" << std::endl;
    choice = getNumber();
    }while(choice < 0 || choice > 2);
    return choice;
}

int getlen(){
    int len;
    std::cout << "Enter length of sequence:" << std::endl;
    do {
        len = getNumber();
    }while(len < 0);
    return len;
}


void menu_main(){
    std::cout<< "Choose action:" <<std:: endl;
    std::cout<< "0. Exit" <<std:: endl;
    std::cout<< "1. Create new" <<std:: endl;
    std::cout<< "2. Shuffle" <<std:: endl;
    std::cout<< "3. Sort" <<std:: endl;
    std::cout<< "4. Print" <<std:: endl;
    std::cout<< "5. Auto check" <<std:: endl;
    std::cout<< "6. Tests" <<std:: endl;
    std::cout<< "7. Time" <<std:: endl;
}
