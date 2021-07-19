#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#define TC 29

//Version 1 made using the concept of struct and functions
//The ranking system is based on the total of points

//Declarion of struct for storage of country data
struct pais
{
    char nome[TC];
    int mgold;
    int msilver;
    int mbronze;
    int pt;
};

//Function for measurement of total of points
int pontuacao(int g,int s,int tb);

//Function made for aesthetics purposes
void distchar(char ct[TC]);

int main ()
{
    setlocale(LC_ALL,"portuguese");

    //Declaration of independent variables 
    int i, j,qp;

    //Scan total number of countries
    printf("Digite a quantidade de países a serem catalogados\n");
    scanf("%d", &qp);

    //Dependent structs
    struct pais p[qp];
    struct pais mc;
    
    //Reading of the data of the enlisted countries
    printf("\n==================================================================================\n");
    for(i=0;i<qp;i+=1)
    {
        printf("Digite o nome do %dº país a ser catalogado\n",i+1);
        getchar( );
        gets(p[i].nome);
        printf("%d\n",strlen(p[i].nome));
        printf("|\t\" %s \"  Medalhas de ouro  -  [5-pts]: ",p[i].nome);
        scanf("%d",&p[i].mgold);
        printf("|\t\" %s \"  Medalhas de prata  -  [3-pts]: ",p[i].nome);
        scanf("%d",&p[i].msilver);
        printf("|\t\" %s \"  Medalhas de bronze  -  [1-pts]: ",p[i].nome);
        scanf("%d",&p[i].mbronze);

        p[i].pt=pontuacao(p[i].mgold,p[i].msilver,p[i].mbronze);
        printf("\n==================================================================================\n");
    }

    //Establishment of the order based on the score system
    for(i=0;i<qp;i+=1)
    {
        for(j=i+1;j<qp;j+=1)
        {
            if(p[j].pt>p[i].pt)
            {
                mc=p[j];
                p[j]=p[i];
                p[i]=mc;
            }
        }
    }

    printf("\n\n\n");
    
    //print of final order
    printf("\t\t\tTabela\n==================================================================================\n");
    printf("Nº|\t\t\tPaís\t\t\t|Ouro\tPrata\tBronze\tPts\n");
    for(i=0;i<qp;i+=1)
    {
        //      Nº|\t\Country\t\t\tGold\tSilver\tBronze\tPts\n
        //      Nº|\t\tPaís\t\t\tOuro\tPrata\tBronze\tPts\n
        printf("%dº-\t\t%s",i+1,p[i].nome);
        distchar(p[i].nome);
        printf(" %d\t%d\t%d\t%d\n",p[i].mgold,p[i].msilver,p[i].mbronze,p[i].pt);
    }
    printf("\n==================================================================================\n");   
}

int pontuacao(int g,int s,int tb)
{
    int tg,ts,total;
    tg=g*5;
    ts=s*3;
    total=tg+ts+tb;
    return total;
}

void distchar(char ct[TC])
{
    int tamc;
    tamc=strlen(ct);
    if(tamc<8) printf("\t\t\t\t");
    else if(tamc<=15) printf("\t\t\t");
    else if(tamc<=22) printf("\t\t");
    else if(tamc<=29) printf("\t");
    
}