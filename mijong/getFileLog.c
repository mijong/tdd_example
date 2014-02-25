#include"getFileLog.h"


struct file_logs get_filelog_row(void)
{
    struct file_logs file_log_values;
    char *pStrtok;
    char file_log_string_buffer[BUFF_SIZE];
    FILE *pPopen;
    int line_number = 0;
    pPopen = popen("df -B 1", "r");

    if (pPopen == NULL) {
        printf("Error:can not get popen\n");
        return file_log_values;
    }

    while (fgets(file_log_string_buffer, BUFF_SIZE, pPopen)) {

        pStrtok = strtok(file_log_string_buffer, " ");

        strcpy(file_log_values.log_lines[line_number].filesystem, pStrtok);
        pStrtok = strtok(NULL, " ");
        strcpy(file_log_values.log_lines[line_number].blocks, pStrtok);
        pStrtok = strtok(NULL, " ");
        strcpy(file_log_values.log_lines[line_number].used, pStrtok);
        pStrtok = strtok(NULL, " ");
        strcpy(file_log_values.log_lines[line_number].available, pStrtok);
        pStrtok = strtok(NULL, " ");
        strcpy(file_log_values.log_lines[line_number].use, pStrtok);
        pStrtok = strtok(NULL, " ");
        strcpy(file_log_values.log_lines[line_number].mounted, pStrtok);
        pStrtok = strtok(NULL, " ");

        line_number++;
    }

    pclose(pPopen);
    return file_log_values;
}
