#include "../inc/Header.h"

void error_output(int errorNum, char *text){
    switch (errorNum) {
        case 1:
            mx_printerr("usage: ./uls [-l] [file ...]\n");
            exit(1);
        case 2:
            mx_printerr("uls: illegal option -- ");
            mx_printerr(text);
            mx_printerr("\n");
            mx_printerr("usage: ./uls [-l] [file ...]\n");
            exit(1);
        case 3:
            mx_printerr("uls: ");
            mx_printerr(text);
            mx_printerr(": No such file or directory\n");
    }
}
