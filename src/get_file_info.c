#include "../inc/Header.h"

t_fdata get_file_info(char* filename){
    struct stat st;
    struct passwd *pw = NULL;
    struct group *group_info;
    
    t_fdata filedata;
    lstat(filename, &st);
    struct timespec timesp = st.st_mtimespec;
    pw = getpwuid(st.st_uid);
    group_info = getgrgid(st.st_gid);
    filedata.name = mx_strdup(filename);
    filedata.creator = mx_strdup(pw->pw_name);
    filedata.accessfor = mx_strdup(group_info->gr_name);
    filedata.time = unixtime_to_str(timesp.tv_sec);
    filedata.size = st.st_size;
    filedata.count_link = st.st_nlink;
    filedata.roots = get_permissions(filename);
    filedata.st_blocks = st.st_blocks;
    return filedata;
}
