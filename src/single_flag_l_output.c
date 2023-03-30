#include "../inc/Header.h"

void single_flag_l_output(t_fdata filedata, int *max_sizes){
    mx_printstr(filedata.roots);
    mx_printchar(' ');
    fill_spaces(max_sizes[1], get_num_len(filedata.count_link));
    mx_printint(filedata.count_link);
    mx_printchar(' ');
    mx_printstr(filedata.creator);
    fill_spaces(max_sizes[2], mx_strlen(filedata.creator));
    mx_printchar(' ');
    mx_printstr(filedata.accessfor);
    fill_spaces(max_sizes[3], mx_strlen(filedata.accessfor));
    fill_spaces(max_sizes[4], get_num_len(filedata.size));
    mx_printlong(filedata.size);
    fill_spaces(max_sizes[5], mx_strlen(filedata.time));
    mx_printstr(filedata.time);
    mx_printchar(' ');
    mx_printstr(filedata.name);
    mx_printchar('\n');
}
