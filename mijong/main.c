#include"get_file_log.h"

void main(void)
{
    struct file_logs log_datas;
    log_datas = get_filelog_row();
    printf("%s\n", log_datas.log_lines[0].filesystem);
}
