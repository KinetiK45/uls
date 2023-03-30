#include "../inc/Header.h"

bool *get_bool_flags_arr(char *str_flags) {
    char flags_chars[FLAGS_AMOUNT] = {'l','a','A','R','G','h','@','e','T',
       '1','C','r','t','u','c','S'};
    bool *bool_flags = malloc(sizeof(bool) * FLAGS_AMOUNT);
    for (int i = 0; i < FLAGS_AMOUNT;i++)
        bool_flags[i] = 0;
    
    int str_flags_len = mx_strlen(str_flags);
    for(int i = 0; i < str_flags_len; i++)
        for (int j = 0; j < FLAGS_AMOUNT; j++) {
            if (str_flags[i] == flags_chars[j]) {
                bool_flags[j] = true;
                break;
            }
        }
    return bool_flags;
}

void initialize_flags_struct(t_flags *flags, char *str_flags) {
    bool *bool_flags_arr = get_bool_flags_arr(str_flags);
    flags->l_flag = bool_flags_arr[0];
    flags->a_flag = bool_flags_arr[1];
    flags->A_flag = bool_flags_arr[2];
    flags->R_flag = bool_flags_arr[3];
    flags->G_flag = bool_flags_arr[4];
    flags->h_flag = bool_flags_arr[5];
    flags->at_flag = bool_flags_arr[6];
    flags->e_flag = bool_flags_arr[7];
    flags->T_flag = bool_flags_arr[8];
    flags->one_flag = bool_flags_arr[9];
    flags->C_flag = bool_flags_arr[10];
    flags->r_flag = bool_flags_arr[11];
    flags->t_flag = bool_flags_arr[12];
    flags->u_flag = bool_flags_arr[13];
    flags->c_flag = bool_flags_arr[14];
    flags->S_flag = bool_flags_arr[15];
    
    free(bool_flags_arr);
}
char *get_flags_string(char **argv) {
    char *res = mx_strnew(10);
    argv++;
    while(*argv) {
        if (argv[0][0] == '-'){
            char *temp = mx_strjoin(res,argv[0]);
            mx_strdel(&res);
            res = temp;
        }
        argv++;
    }
    return res;
}

t_flags *get_flags(int argc, char * argv[]) {
    t_flags *flags = (t_flags*)malloc(sizeof(t_flags));
    char *str_flags = mx_strdup("");
    if (argc > 1){
        char *temp = get_flags_string(argv);
        mx_strdel(&str_flags);
        str_flags = temp;
    }
    initialize_flags_struct(flags, str_flags);
    mx_strdel(&str_flags);
    return flags;
    
}
