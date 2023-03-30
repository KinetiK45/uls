#include "../inc/Header.h"

void fill_spaces(int max_size, int len){
    mx_printchar(' ');
    if (len == 0) len = 1;
    for (int i = 0; i < max_size - len; i++) {
        mx_printchar(' ');
    }
}
