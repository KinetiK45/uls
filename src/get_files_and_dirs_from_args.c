#include "../inc/Header.h"

char** get_files_and_dirs_from_args(int argc, char *argv[]) {
    char** result = NULL;
    int result_index = 0;
    bool have_dirs = false;
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            have_dirs = true;
            char* file_or_dir_name = argv[i];
            if (check_path(file_or_dir_name) < 1){
                error_output(3, file_or_dir_name);
                continue;
            }
            char* new_str = mx_strdup(file_or_dir_name);
            result = mx_realloc(result, (result_index + 1) * sizeof(char*));
            result[result_index] = new_str;
            result_index++;
        }
    }
    if (!have_dirs){
        result = mx_realloc(result, (result_index + 1) * sizeof(char*));
        result[result_index] = mx_strdup(".");
        result_index++;
    }
    
    result = mx_realloc(result, (result_index + 1) * sizeof(char*));
    result[result_index] = NULL;

    return result;
}
