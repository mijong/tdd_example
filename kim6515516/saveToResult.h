#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 1024
#define STR_SIZE 100


struct DF_PRINT_FORMAT 
{
	char fileSystemName[STR_SIZE];
	char blockSize[STR_SIZE];
	char used[STR_SIZE];
	char avalable[STR_SIZE];
	char usedPercent[STR_SIZE];
	char mountOn[STR_SIZE];
}; 

int saveToResult(void);
