#include "../inc/Header.h"

t_fdata *get_data_from_directory(char *directory){
    DIR* fd;
    struct dirent *dir = NULL;
    if((fd = opendir(directory)) == NULL){
        error_output(3, directory);
        return NULL;
    }
    
    dir = readdir(fd);
    t_fdata *fdata_list = NULL;
    for (int i = 0; dir; i++) {
        t_fdata filedata = fill_data(dir, directory);
        push_back_fdata(&fdata_list, filedata);
        dir = readdir(fd);
    }
    return fdata_list;
}
