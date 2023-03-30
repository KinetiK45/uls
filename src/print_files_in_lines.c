#include "../inc/Header.h"

void print_files_in_lines(t_fdata *fdata_list){
    t_fdata *temp = fdata_list;
    while (temp) {
        if (temp->name[0] != '.'){
            single_no_flags_output(*temp);
        }
        temp = temp->next;
    }
}
