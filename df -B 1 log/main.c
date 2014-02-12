#include <stdio.h>
#include <stdlib.h>
#define buffsize  1024

    struct filelog
    {
    char Filesystem[20];
    char Blocks[20];
    char Used[20];
    char Available[20];
    char Use[20];
    char Mounted[20];
    };
    int i=0,j=0;

int main(void)
{
    struct filelog log[10];
    char *ptr;
    char buff[buffsize];
    FILE *fp;
    fp=popen("df -B 1","r");

    for(i=0;i<6;i++)// if you want more log increse i 
    {
        fgets(buff,buffsize,fp);
        ptr=strtok(buff," ");
        j=0;

        while(ptr!=NULL)
        {
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
    //example of log pop
    //save log in filelog struct
    //how to use 
    // log[number].Filesystem//--> call filesystem
    // log[number].Blocks//-- > call blocks
    //number is line number number 0 is first line 
    printf("%s\n",log[1].Mounted);
    pclose(fp);
    return 0;
}