#include "../inc/Header.h"

t_fdata* get_files_info(char** files_and_dirs){
    t_fdata* result = NULL;
    for (int i = 0; files_and_dirs[i]; i++) {
        if (check_path(files_and_dirs[i]) == 2){
            push_back_fdata(&result, get_file_info(files_and_dirs[i]));
        }
    }
    return result;
}
