#include "../inc/Header.h"

void free_data(t_fdata data){
    mx_strdel(&data.name);
    mx_strdel(&data.time);
    mx_strdel(&data.creator);
    mx_strdel(&data.roots);
    mx_strdel(&data.accessfor);
}

void free_data_list(t_fdata *data){
    t_fdata *temp = data;
    while (temp) {
        t_fdata *pointer = temp->next;
        free_data(*temp);
        free(temp);
        temp = NULL;
        temp = pointer;
    }
}
