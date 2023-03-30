#include "../inc/Header.h"

void fill_tabs_to_maxsize(int max_len, int len){
    int need_tabs = max_len/8 + 1;
    int count_tabs = need_tabs - len/8;
    for (int i = 0; i < count_tabs; i++) {
        mx_printchar('\t');
    }
}

void print_files_in_columns(t_fdata *head_ref) {
    t_fdata *head_do_hiden_files = head_ref;
    while (head_do_hiden_files->name[0] == '.') {
        head_do_hiden_files = head_do_hiden_files->next;
    }
    t_fdata *current = head_do_hiden_files;
    struct winsize w;
    int max_len = 0, num_files = 0, num_cols = 0, num_rows = 0, i, j;

    while (current != NULL) {
        if (current->name[0] == '.'){
            current = current->next;
            continue;
        }
        int len = mx_strlen(current->name);
        if (len > max_len) {
            max_len = len;
        }
        current = current->next;
        num_files++;
    }
    current = head_do_hiden_files;

    ioctl(0, TIOCGWINSZ, &w);
    double num_cols_dub = (double) w.ws_col / ((double) max_len + 8 - (max_len % 8));
    num_cols = (int) num_cols_dub;
    num_rows = (num_files + num_cols - 1) / num_cols;
    if (num_cols < 2){
        print_files_in_lines(head_ref);
        return;
    }

    char **file_names = malloc(num_files * sizeof(char *));
    int iter = 0;
    while (iter < num_files) {
        if (current->name[0] != '.'){
            file_names[iter++] = current->name;
        }
        current = current->next;
    }
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            int index = j * num_rows + i;
            if (index < num_files) {
                mx_printstr(file_names[index]);
                if ((j+1) * num_rows + i < num_files){
                    int len = mx_strlen(file_names[index]);
                    fill_tabs_to_maxsize(max_len, len);
                }
            }
        }
        mx_printchar('\n');
    }
    free(file_names);
}
