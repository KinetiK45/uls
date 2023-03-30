#include "../inc/Header.h"

char* create_path(char *link, char *dir){
    char *temp = mx_strjoin(link, "/");
    char *result = mx_strjoin(temp, dir);
    mx_strdel(&temp);
    return result;
}

t_fdata fill_data(struct dirent *dir, char *path){
    struct stat st;
    struct passwd *pw = NULL;
    struct group *group_info;
    
    t_fdata filedata;
    char *fullPath = create_path(path, dir->d_name);
    lstat(fullPath, &st);
    struct timespec timesp = st.st_mtimespec;
    pw = getpwuid(st.st_uid);
    group_info = getgrgid(st.st_gid);
    filedata.name = mx_strdup(dir->d_name);
    filedata.creator = mx_strdup(pw->pw_name);
    filedata.accessfor = mx_strdup(group_info->gr_name);
    filedata.time = unixtime_to_str(timesp.tv_sec);
    filedata.size = st.st_size;
    filedata.count_link = st.st_nlink;
    filedata.roots = get_permissions(fullPath);
    filedata.st_blocks = st.st_blocks;
    
    mx_strdel(&fullPath);
    return filedata;
}
