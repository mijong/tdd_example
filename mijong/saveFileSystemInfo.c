#include"saveFileSystemInfo.h"


void saveFileLog(void)
{

    char *pStrtok;
    char filelogStringBuffer[BUFF_SIZE];
    FILE *pPopen;
    int logLineNumber = 0;
    pPopen = popen("df -B 1", "r");

    if (pPopen == NULL) {
        printf("Error:can not get popen\n");
        return 0;
    }

    while (fgets(filelogStringBuffer, BUFF_SIZE, pPopen)) {

        pStrtok = strtok(filelogStringBuffer, " ");
        strcpy(diskState[logLineNumber].filesystem, pStrtok);
        pStrtok = strtok(NULL, " ");
        strcpy(diskState[logLineNumber].blocks, pStrtok);
        pStrtok = strtok(NULL, " ");
        strcpy(diskState[logLineNumber].used, pStrtok);
        pStrtok = strtok(NULL, " ");
        strcpy(diskState[logLineNumber].available, pStrtok);
        pStrtok = strtok(NULL, " ");
        strcpy(diskState[logLineNumber].use, pStrtok);
        pStrtok = strtok(NULL, " ");
        strcpy(diskState[logLineNumber].mounted, pStrtok);
        pStrtok = strtok(NULL, " ");
        logLineNumber++;
    }

    pclose(pPopen);
}
