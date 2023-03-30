#include "../inc/Header.h"

void print_dirs(char** files_and_dirs, t_flags *flags, bool have_files){
    char** dirs = NULL;
    int dirs_index = 0;
    for (int i = 0; files_and_dirs[i]; i++) {
        if (check_path(files_and_dirs[i]) == 1) {
            char* dir = files_and_dirs[i];
            char* new_str = mx_strdup(dir);
            dirs = mx_realloc(dirs, (dirs_index + 1) * sizeof(char*));
            dirs[dirs_index] = new_str;
            dirs_index++;
        }
    }
    dirs = mx_realloc(dirs, (dirs_index + 1) * sizeof(char*));
    dirs[dirs_index] = NULL;
    
    int size_dirs = dirs_index;
    
    mx_bubble_sort(dirs, size_dirs);
    
    for (int i = 0; i < size_dirs; i++) {
        if (size_dirs > 1 || have_files){
            if (have_files)
                mx_printchar('\n');
            else
                have_files = true;
            mx_printstr(dirs[i]);
            mx_printstr(":\n");
        }
        t_fdata *fdata_list = get_data_from_directory(dirs[i]);
        data_output(fdata_list, flags, true);
        free_data_list(fdata_list);
    }
    if (dirs)
        mx_del_strarr(&dirs);
}
