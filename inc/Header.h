#ifndef Header_h
#define Header_h

#include "../libmx/inc/libmx.h"

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/errno.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <time.h>

typedef struct s_fdata {
    char *roots;
    int count_link;
    char *creator;
    char *accessfor;
    long size;
    char *time;
    char *name;
    long st_blocks;
    struct s_fdata* next;
}             t_fdata;

typedef struct s_flags {
    bool l_flag,
    a_flag, A_flag,
    R_flag, G_flag,
    h_flag, at_flag,
    e_flag, T_flag,
    one_flag, C_flag,
    r_flag, t_flag,
    u_flag,c_flag,S_flag;
}             t_flags;

#define FLAGS_AMOUNT 16

void check_input_validity(int argc, char **argv);
//long mx_atol(char *str);
void mx_printlong(long n);
int check_path(char *path);
void error_output(int errorNum, char *text);
void check_args(int argc, char *argv[]);
t_fdata *create_fdata(t_fdata data);
void push_back_fdata(t_fdata **list, t_fdata data);
char* get_permissions(char *file_path);
t_fdata fill_data(struct dirent *dir, char *path);
void free_data(t_fdata data);
void free_data_list(t_fdata *data);
t_fdata *get_data_from_directory(char *directory);
t_flags *get_flags(int argc, char * argv[]);

//my new
void data_output(t_fdata *fdatalist, t_flags *flags, bool print_total);
void fill_spaces(int max_size, int len);
int* get_count_spaces_in_output(t_fdata *fdatalist);
void print_blocks(t_fdata *fdatalist);
void single_flag_l_output(t_fdata filedata, int *max_sizes);
void single_no_flags_output(t_fdata filedata);
char *unixtime_to_str(time_t time_of_file);
void sort_t_fdata_by_name(t_fdata *head_ref);
void print_flag_l(t_fdata *fdata_list, bool print_total);
void print_files_in_lines(t_fdata *fdata_list);
void print_files_in_columns(t_fdata *head_ref);
t_fdata get_file_info(char* filename);
char** get_files_and_dirs_from_args(int argc, char *argv[]);
t_fdata* get_files_info(char** files_and_dirs);
void print_dirs(char** files_and_dirs, t_flags *flags, bool have_files);
int get_num_len(long number);

#endif
