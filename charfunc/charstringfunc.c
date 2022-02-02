#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int charcon(void)
{
    char c;
    do
    {
        printf("Press any button\n");
        getchar();
        c = getchar();
        if (c >=65 && c <= 90)
        {
            c=c+(97-65);
        }
        putchar(c);
        putchar('\n');
    }
    while(conti());
}

int stringcon(void)
{
    char s[50];
    int l,i;
    getchar();
    do
    {
        printf("\nWrite any string\n");
        gets(s);
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if (s[i] >=65 && s[i] <= 90)
            {
                s[i]=s[i]+(97-65);
            }
        }
        printf("\"%s\"\n",s);
        
    }
    while(conti());
}

int conti(void)
{
    char yn;
    while(1)
    {
        printf("Continue? [y/n]  ");
        
        yn = getchar();
        getchar();
        if(yn=='N' || yn=='Y') 
        {
            yn=yn+(97-65);
        }
        putchar(yn);
        if (yn=='y') return 1;
        else if(yn=='n') return 0;
        else putchar('\n');
    }
}

main()
{
    int yn;
    printf("CAPITAL LETTER CONVERSOR\n\n");
    do
    {
        printf("Choose format\n1-\tChar\n2-\tString\n0-\tStop program\n");
        scanf("%d",&yn);
        switch(yn)
        {
            case 0: return;
            case 1:
            case 2: break;
            default: printf("Unavailable format\v");
        }
    }
    while(!(yn>=0 && yn<=2));
    if(yn==1)
    {
        charcon();
    }
    else if(yn==2)
    {
        stringcon();
    }
    printf("\n********************\n");
    printf(  "*PROGRAM TERMINATED*\n");
    printf(  "********************\n");
}