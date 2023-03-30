#include "../inc/Header.h"

int* get_count_spaces_in_output(t_fdata *fdatalist){
    int *max_sizes = (int*)malloc(sizeof(int) * 7);
    for (int i = 0; i < 7; i++) {
        max_sizes[i] = 0;
    }
    t_fdata *temp = fdatalist;
    while (temp) {
        if (max_sizes[0] < mx_strlen(temp->roots))
            max_sizes[0] = mx_strlen(temp->roots);
        if (max_sizes[1] < get_num_len(temp->count_link))
            max_sizes[1] = get_num_len(temp->count_link);
        if (max_sizes[2] < mx_strlen(temp->creator))
            max_sizes[2] = mx_strlen(temp->creator);
        if (max_sizes[3] < mx_strlen(temp->accessfor))
            max_sizes[3] = mx_strlen(temp->accessfor);
        if (max_sizes[4] < get_num_len(temp->size))
            max_sizes[4] = get_num_len(temp->size);
        if (max_sizes[5] < mx_strlen(temp->time))
            max_sizes[5] = mx_strlen(temp->time);
        if (max_sizes[6] < mx_strlen(temp->name))
            max_sizes[6] = mx_strlen(temp->name);
        temp = temp->next;
    }
    return max_sizes;
}
