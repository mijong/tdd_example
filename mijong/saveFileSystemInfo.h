#include <stdio.h>
#include <string.h>
#define BUFF_SIZE 1024
#define STR_SIZE 100
#define LINE_SIZE 100


struct file_Log
{
    char filesystem[STR_SIZE];
    char blocks[STR_SIZE];
    char used[STR_SIZE];
    char available[STR_SIZE];
    char use[STR_SIZE];
    char mounted[STR_SIZE];
    char on[STR_SIZE];
};

struct file_Log log[LINE_SIZE];

void save_FileLog(void)
{

    char *ptr;//pointer of strtok
    char string_Buffer[BUFF_SIZE];
    FILE *fp;// file pointer 
    int line_Number=0;
    fp=popen("df -B 1","r");


	while(fgets(string_Buffer,BUFF_SIZE,fp))
	{
        ptr=strtok(string_Buffer," ");
        strcpy(log[line_Number].filesystem,ptr);	
        ptr=strtok(NULL," ");
        strcpy(log[line_Number].blocks,ptr);
        ptr=strtok(NULL," ");
        strcpy(log[line_Number].used,ptr);
        ptr=strtok(NULL," ");
        strcpy(log[line_Number].available,ptr);
        ptr=strtok(NULL," ");
        strcpy(log[line_Number].use,ptr);
        ptr=strtok(NULL," ");
        strcpy(log[line_Number].mounted,ptr);
        ptr=strtok(NULL," ");
        line_Number++;
	}

    pclose(fp);
}







