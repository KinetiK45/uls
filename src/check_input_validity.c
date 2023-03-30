#include "../inc/Header.h"

void check_invalid_flags(char **argv) {
    char flags_chars[FLAGS_AMOUNT] = {'l','a','A','R','G','h','@','e','T',
        '1','C','r','t','u','c','S'};
    bool is_valid_flag = false;
    bool is_correct_to_check = false;
    int i = 1,j = 0;
    argv++;
    while(*argv) {
        if (!is_correct_to_check && i > 1)
            break;
        
        is_correct_to_check = false;
        
        if(argv[0][0] == '-') {
            is_correct_to_check = true;
            for (i = 1; i < mx_strlen(argv[0]); i++) {
                for (j = 0; j < FLAGS_AMOUNT; j++) {
                    if (argv[0][i] == flags_chars[j]) {
                        is_valid_flag = true;
                        break;
                    }
                }
                if (!is_valid_flag) {
                    char *str_flag = mx_strdup("");
                    str_flag[0] = argv[0][i];
                    error_output(2, str_flag);
                    mx_strdel(&str_flag);
                }
                
                is_valid_flag = false;
            }
        }
        argv++;
    }
}
void check_input_validity(int argc,char *argv[]) {
    if (argc > 1)
        check_invalid_flags(argv);
}

