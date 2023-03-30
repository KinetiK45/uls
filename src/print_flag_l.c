#include "../inc/Header.h"

void print_flag_l(t_fdata *fdata_list, bool print_total){
    if (print_total)
        print_blocks(fdata_list);
    int *max_sizes = get_count_spaces_in_output(fdata_list);
    t_fdata *temp = fdata_list;
    while (temp) {
        if (temp->name[0] != '.'){
            single_flag_l_output(*temp, max_sizes);
        }
        temp = temp->next;
    }
    free(max_sizes);
}
