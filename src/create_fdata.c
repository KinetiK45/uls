#include "../inc/Header.h"

t_fdata *create_fdata(t_fdata data) {
    t_fdata *node = malloc(sizeof(t_fdata));
    *node = data;
    node->next = NULL;
    return node;
}
