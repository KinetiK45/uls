#include "../inc/Header.h"

long mx_atol(char *str) {
    bool is_negative = false;
    if (mx_get_substr_index(str, "-") != -1)
        is_negative = true;
    long int res = 0;
    while (*str) {
        if(mx_isdigit(*str)){
            res = res * 10;
            res = res + (*str - 48);
        }
        str++;
    }
    if(is_negative)
        res *= -1;
    return res;
}
