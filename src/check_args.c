#include "../inc/Header.h"

void check_args(int argc, char *argv[]){
    t_flags *flags = get_flags(argc,argv);
    
    char** files_and_dirs = get_files_and_dirs_from_args(argc, argv);
    
    t_fdata* files_info = get_files_info(files_and_dirs);
    
    if (files_info){
        data_output(files_info, flags, false);
        print_dirs(files_and_dirs, flags, true);
    }
    else
        print_dirs(files_and_dirs, flags, false);
    
    free(flags);
    free_data_list(files_info);
    mx_del_strarr(&files_and_dirs);
}
