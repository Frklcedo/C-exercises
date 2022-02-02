#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>
#define TAM 5

main()
{
    setlocale(LC_ALL,"portuguese");
    
    int i,j,cond;
    int vetor[TAM];
    srand(time(NULL));

    for (i=0;i< TAM;i++)
    {
        if(i==0)
        {
            vetor[i]=rand() % 5;
        }
        else
        {
            cond=1;
            while(cond!=0)
            {
                cond=0;
                vetor[i]=rand() % 5;
                for(j=i-1;j>=0;j=j-1)
                {
                    if(vetor[i]==vetor[j])
                    {
                        cond++;
                    }
                }
            }
        }
        printf("%d\n",vetor[i]);
    }

}