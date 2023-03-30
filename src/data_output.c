#include "../inc/Header.h"

void data_output(t_fdata *fdatalist, t_flags *flags, bool print_total){
    t_fdata *temp = fdatalist;
    sort_t_fdata_by_name(temp);
    if (flags->l_flag){
        print_flag_l(temp, print_total);
    }
    else{
        if (isatty(1)) {
            print_files_in_columns(temp);
        } else {
            print_files_in_lines(temp);
        }
    }
}
