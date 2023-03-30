#include "../inc/Header.h"

char **get_time_arr_from_unix_time(time_t time){
    char *fulltime = mx_strndup(ctime(&time), mx_strlen(ctime(&time)) - 1);
    char **fulltime_split = mx_strsplit(fulltime, ' ');
    mx_strdel(&fulltime);
    return fulltime_split;
}

char *get_hh_mm(char *hhMMss){
    return mx_strndup(hhMMss, 5);
}

char *unixtime_to_str(time_t time_of_file){
    char *result;
    char **fulltime_split = get_time_arr_from_unix_time(time_of_file);
    time_t now = time(0);
    
    char *temp;
    if (mx_strlen(fulltime_split[2]) == 1){
        temp = mx_strjoin(fulltime_split[1], "  ");
    }
    else {
        temp = mx_strjoin(fulltime_split[1], " ");
    }
    char *month_with_day = mx_strjoin(temp, fulltime_split[2]);
    mx_strdel(&temp);
    
    if (time_of_file < now - 15768000){
        char *year = mx_strjoin("  ", fulltime_split[4]);
        result = mx_strjoin(month_with_day, year);
        mx_strdel(&year);
    }
    else {
        char *hhMM = get_hh_mm(fulltime_split[3]);
        temp = mx_strjoin(" ", hhMM);
        result = mx_strjoin(month_with_day, temp);
        mx_strdel(&temp);
        mx_strdel(&hhMM);
    }
    mx_strdel(&month_with_day);
    mx_del_strarr(&fulltime_split);
    return result;
}
