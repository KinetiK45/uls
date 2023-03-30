#include "../inc/Header.h"

char* get_permissions(char *file_path){
    struct stat st;
    char *modeval = mx_strnew(10);
    if(stat(file_path, &st) != 0)
        return NULL;
    mode_t perm = st.st_mode;
    modeval[0] = (perm & S_IFDIR) ? 'd' : '-';
    modeval[1] = (perm & S_IRUSR) ? 'r' : '-';
    modeval[2] = (perm & S_IWUSR) ? 'w' : '-';
    modeval[3] = (perm & S_IXUSR) ? 'x' : '-';
    modeval[4] = (perm & S_IRGRP) ? 'r' : '-';
    modeval[5] = (perm & S_IWGRP) ? 'w' : '-';
    modeval[6] = (perm & S_IXGRP) ? 'x' : '-';
    modeval[7] = (perm & S_IROTH) ? 'r' : '-';
    modeval[8] = (perm & S_IWOTH) ? 'w' : '-';
    modeval[9] = (perm & S_IXOTH) ? 'x' : '-';
    return modeval;
}
