#include "../inc/Header.h"

int get_num_len(long number){
    if (number == 0) return 1;
    int size = 0;
    if (number < 0){
        size = 1;
        number *= -1;
    }
    while (number != 0) {
        size++;
        number /= 10;
    }
    return size;
}
