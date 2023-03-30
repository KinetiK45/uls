#include "../inc/Header.h"

int check_path(char *path) {
    struct stat st;
    if( stat(path,&st) == 0 )
    {
        if( st.st_mode & S_IFDIR )
        {
            return 1; //dir
        }
        else if( st.st_mode & S_IFREG )
        {
            return 2; //file
        }
        else
        {
            return 0; //nothing
        }
    }
    return -1;
}
