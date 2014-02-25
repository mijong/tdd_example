#include <stdio.h>
#include <string.h>
#define BUFF_SIZE 1024
#define STR_SIZE 100
#define LOG_LINE_SIZE 100

struct  file_log {
    char filesystem[STR_SIZE];
    char blocks[STR_SIZE];
    char used[STR_SIZE];
    char available[STR_SIZE];
    char use[STR_SIZE];
    char mounted[STR_SIZE];
    char on[STR_SIZE];
};


struct file_logs {
   struct file_log  log_lines[LOG_LINE_SIZE];
};



struct file_logs  get_filelog_row(void);

