#include "../inc/Header.h"

void push_back_fdata(t_fdata **list, t_fdata data){
    if (!*list){
        *list = create_fdata(data);
    }
    else{
        t_fdata *temp = *list;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = create_fdata(data);
    }
}
