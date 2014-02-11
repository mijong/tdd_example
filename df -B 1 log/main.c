#include <stdio.h>
#include <stdlib.h>

struct filelog{
char Filesystem[20];
char Blocks[20];
char Used[20];
char Available[20];
char Use[20];
char Mounted[20];

};

#define buffsize  1024

int i=0,j=0;

int main(void)
{

struct filelog log[10];
char *ptr;

char buff[buffsize];
FILE *fp;

fp=popen("df -B 1","r");

	for(i=0;i<6;i++)
	{
	fgets(buff,buffsize,fp);
	ptr=strtok(buff," ");
	j=0;
	while(ptr!=NULL)
	{//printf("%s\n",ptr);
	if(j==0)
	strcpy(log[i].Filesystem,ptr);
	else if(j==1)
	strcpy(log[i].Blocks,ptr);
	else if(j==2)
	strcpy(log[i].Used,ptr);
	else if(j==3)
	strcpy(log[i].Available,ptr);
	else if(j==4)
	strcpy(log[i].Use,ptr);
	else if(j==5)
	{strcpy(log[i].Mounted,ptr);}
	ptr=strtok(NULL," ");
	
	j++;
	}
	}

	printf("%s\n",log[1].Mounted);
	pclose(fp);

return 0;
}
