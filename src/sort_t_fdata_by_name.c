#include "../inc/Header.h"

void sort_t_fdata_by_name(t_fdata *head_ref) {
    t_fdata *sorted = NULL;
    t_fdata *current = head_ref;

    while (current != NULL) {
        t_fdata *next = current->next;
        
        if (sorted == NULL || mx_strcmp(current->name, sorted->name) < 0) {
            current->next = sorted;
            sorted = current;
        }
        else {
            t_fdata *temp = sorted;
            while (temp->next != NULL && mx_strcmp(current->name, temp->next->name) > 0) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head_ref = sorted;
}
