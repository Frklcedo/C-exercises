#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//Version 0 

int main()
{
    setlocale(LC_ALL,"portuguese");

    int np,maiorpontos,maiorgold,maiorsilver,maiorbronze;
    printf("Quantos países serão catalogados?\n");
    scanf("%d",&np);
    char paises[np][50];
    char maiorp[50];
    int gold[np],silver[np],bronze[np],points[np];
    for (int i=0;i<np;i++)
    //ouro = 5 pontos, prata = 3 pontos, bronze = 1 ponto
    {
        printf("______________________________________________\n");
        printf("Digite o nome do %dº país a ser catalogado\n",i+1);
        //scanf(" %s",&paises[i]);
        getchar( ); // ou fflush(stdin);
        gets(paises[i]);
        //fgets(paises[i],50, stdin); // para não precisar colocar o getchar() para limpar o buffer

        printf("%s\n",paises[i]);
        printf("Quantas medalhas de ouro [ %s ] recebeu?\n",paises[i]);
        scanf("%i",&gold[i]);
        printf("Quantas medalhas de prata [ %s ] recebeu?\n",paises[i]);
        scanf("%i",&silver[i]);
        printf("Quantas medalhas de bronze [ %s ] recebeu?\n",paises[i]);
        scanf("%i",&bronze[i]);
        points[i]=gold[i]*5+silver[i]*3+bronze[i];
        printf("______________________________________________\n");
    }
    for (int i=0;i<np;i++)
    {
        for (int j=0;j<np;j++)
        {
            if(points[j]>points[i] && j>i)
            {
                
                maiorpontos=points[j];
                points[j]=points[i];
                points[i]=maiorpontos;

                maiorgold = gold[j];
                gold[j] = gold[i];
                gold[i] = maiorgold;

                maiorsilver = silver[j];
                silver[j] = silver[i];
                silver[i] = maiorsilver;

                maiorbronze = bronze[j];
                bronze[j] = bronze[i];
                bronze[i] = maiorbronze;

                /*
                maiorp[50]=paises[j][50];
                paises[j][50]=paises[i][50];
                paises[i][50]=maiorp[50];*/
                strcpy(maiorp,paises[j]);
                strcpy(paises[j],paises[i]);
                strcpy(paises[i],maiorp);
            }
        }
    }
    printf("Colocados\n---------\nnº\tPais\tOuro\tPrata\tBronze\tPts\n");
    printf("--------------------------------------------------------------\n");

    for (int i=0;i<np;i++)
    {
        //      nº\tPais\tOuro\tPrata\tBronze\tPts\n 
        printf("%iº:\t%s \t %d \t %d \t %d \t %i\n",i+1,paises[i],gold[i],silver[i],bronze[i],points[i]);
    }
}