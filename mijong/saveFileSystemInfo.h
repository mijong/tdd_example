#include <stdio.h>
#include <string.h>
#define BUFF_SIZE 1024
#define STR_SIZE 100
#define LINE_SIZE 100


struct fileLog
{
    char filesystem[STR_SIZE];
    char blocks[STR_SIZE];
    char used[STR_SIZE];
    char available[STR_SIZE];
    char use[STR_SIZE];
    char mounted[STR_SIZE];
    char on[STR_SIZE];
};

struct fileLog log[LINE_SIZE];

void saveFileLog(void)
{

    char *ptr;//pointer of strtok
    char stringBuffer[BUFF_SIZE];
    FILE *fp;// file pointer 
    int lineNumber=0;
    fp=popen("df -B 1","r");


	while(fgets(stringBuffer,BUFF_SIZE,fp))
	{
        ptr=strtok(stringBuffer," ");
        strcpy(log[lineNumber].filesystem,ptr);	
        ptr=strtok(NULL," ");
        strcpy(log[lineNumber].blocks,ptr);
        ptr=strtok(NULL," ");
        strcpy(log[lineNumber].used,ptr);
        ptr=strtok(NULL," ");
        strcpy(log[lineNumber].available,ptr);
        ptr=strtok(NULL," ");
        strcpy(log[lineNumber].use,ptr);
        ptr=strtok(NULL," ");
        strcpy(log[lineNumber].mounted,ptr);
        ptr=strtok(NULL," ");
        lineNumber++;
	}

    pclose(fp);
}







