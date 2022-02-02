#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isdigit(char c)
{
    return (c>=48 && c<=57);
}

main()
{
    int i;
    char cc;
    printf("ACII\n");
    for(int i = 0; i<128;i++)
    {
        printf(" %c\t=\t%d\n",(char)i,i);
    }
    
    while(1)
    {
        printf("Press any button\n");
        cc=getchar();
        getchar();
        if(!isdigit(cc))
        {
            printf("%c\t=\t%d\n",cc,cc);
        }
    }

}