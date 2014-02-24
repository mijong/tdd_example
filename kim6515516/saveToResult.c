#include "saveToResult.h"


int saveToResult(void)
{
	struct DF_PRINT_FORMAT  fileSystemList[100] ;


	char buff[BUFF_SIZE];
	char *p;

	FILE *fp;
	int count = 0;
	int index = 0;
	int i = 0;
	fp = popen("df -B 1", "r");

	if( NULL == fp)
	{
		perror("failed to popen");
		return -1;
	}
	
	while(fgets(buff, BUFF_SIZE, fp))
	{
		count = 1;
		p = strtok(buff, " ");
		strcpy(fileSystemList[index].fileSystemName, p);
		while(p!=NULL)
		{
			p = strtok(NULL, " ");
		//	if(p) printf("%s\n", p);
			

			switch(count)
			{
				case 1:
				strcpy(fileSystemList[index].blockSize, p);
				break;
				case 2:
				strcpy(fileSystemList[index].used, p);
				break;
				case 3:
				strcpy(fileSystemList[index].avalable , p);
				break;
				case 4:
				strcpy(fileSystemList[index].usedPercent , p);
				break;
				case 5:
				strcpy(fileSystemList[index].mountOn,  p);
				break;
			}
			
			count++;
		}

		count = 1;
		index ++;
	}		

		

	for(i = 1; i< index ; i++)
	{

		printf("%s %s\n", fileSystemList[i].fileSystemName, fileSystemList[i].blockSize);
	}

	pclose(fp);

	return 0;
}
