#include <iostream>
#include "test.h"
#include "sequence.h"
#include "arrayseq.h"
#include "linkedlistseq.h"
#include <ctime>
#include "comparator.h"
#include "timer.h"
#include "Isorter.h"
#include "menu.h"
#include "functs.h"


int main() {
    int choice;
    ISorter<int> tmp;
    Sequence<int> *seq = nullptr;
    while(true){
        menu_main();
        choice = getNumber();
        switch(choice){
            case 0:
                if(seq)
                    delete seq;
                return 0;
            case 1: {
                if (seq) delete seq;
                switch (menu_type()) {
                    case 0:
                        return 0;
                    case 1:
                        seq = new ArraySequence<int>();
                        fill(seq, getlen());
                        break;
                    case 2:
                        seq = new LinkedListSequence<int>();
                        fill(seq, getlen());
                        break;
                }
            }
            case 2:{
                if(!seq)
                    std::cout << "\nNo sequences" << std::endl;
                else{
                    shuffle(seq);
                }
                break;
            }
            case 3: {
                if (!seq)
                    std::cout << "\nNo sequences" << std::endl;
                else {
                    switch (menu_sort()) {
                        case 0:
                            return 1;
                        case 1:
                            switch (menu_order()) {
                                case 0:
                                    return 1;
                                case 1:
                                    tmp.quick(seq, compare_asc);
                                    break;
                                case 2:
                                    tmp.quick(seq, compare_dsc);
                                    break;
                            }
                            break;
                        case 2:
                            switch (menu_order()) {
                                case 0:
                                    return 1;
                                case 1:
                                    tmp.bubble(seq, compare_asc);
                                    break;
                                case 2:
                                    tmp.bubble(seq, compare_dsc);
                                    break;
                            }
                            break;
                        case 3:
                            switch (menu_order()) {
                                case 0:
                                    return 1;
                                case 1:
                                    tmp.insertion(seq, compare_asc);
                                    break;
                                case 2:
                                    tmp.insertion(seq, compare_dsc);
                                    break;
                            }
                            break;
                        case 4:
                            switch (menu_order()) {
                                case 0:
                                    return 1;
                                case 1:
                                    tmp.selection(seq, compare_asc);
                                    break;
                                case 2:
                                    tmp.selection(seq, compare_dsc);
                                    break;
                            }
                            break;


                    }
                }
                break;
            }
            case 4: {
                if (!seq)
                    std::cout << "\nNo sequences" << std::endl;
                else {
                    seq->print();
                    break;
                }
            }
            case 5: {
                if (!seq)
                    std::cout << "\nNo sequences" << std::endl;
                else {
                    checkSort(seq);
                }
                break;
            }
            case 6:{
                test();
                break;
            }
            case 7: {
                timing(getlen());
                break;
            }
        }
    }



    return 0;
}
