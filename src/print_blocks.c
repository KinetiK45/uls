#include "../inc/Header.h"

void print_blocks(t_fdata *fdatalist){
    long total_blocks = 0;
    t_fdata *temp = fdatalist;
    while (temp->next) {
        if (temp->name[0] != '.')
            total_blocks += temp->st_blocks;
        temp = temp->next;
    }
    if (temp->name[0] != '.')
        total_blocks += temp->st_blocks;
    mx_printstr("total ");
    if (total_blocks == 0) mx_printstr("0");
    else{
        mx_printlong(total_blocks);
        //mx_printint((int)total_blocks); //сделать функцию для лонг
    }
    mx_printchar('\n');
}
