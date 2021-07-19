#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#define TT 29

//Version 2 [pointers, functions etc]
/*
The ranking system is based on gold medals{
    If number of gold medals between countries are even, then the number of silver medals will hold value{
        If number of silver medals between countries are even, then the number of bronze medals will hold value{
            If number of bronze medals are also even, then the point addition/deduction system will count
        }
    }
}        
*/

//Struct made to store data of the countries enlisted 
struct pais
{
    char nm[29];
    int mg;
    int ms;
    int mb;
    int pts;
};

//Function made to calculate total number of points based on the medals earned
int pontuacao(int g,int s,int tb);

//Function made for aesthetics purposes
void distchar(char ct[TT]);

/*Function made to organize the countries enlisted based on:
    1- Number of gold medals
    2- Number of silver medals
    3- Numbers of bronze medals
    4- Points deducted
*/
void ord(struct pais *p, int np);

int main()
{
    setlocale(LC_ALL,"portuguese");

    //Declaration of variables
    int np,i,cont,red,sum;
    char pen;
    
    //Reading of the number of countries that will be enlisted
    printf("Digite a quantidade de países para a tabela\n");
    scanf("%d", &np);

    struct pais p[np];

    printf("\n==================================================================================\n");
    for(i=0;i<np;i++)
    {
        //Name of the country
        printf("| Digite o nome do %dº país\n",i+1);
        getchar( );
        gets(p[i].nm);

        //Number of medals [Gold/Silver/Bronze]    
        printf("||\t \"%s\"  -  Medalhas de Ouro [5-pts]: ",p[i].nm);
        scanf("%d", &p[i].mg);
        printf("||\t \"%s\"  -  Medalhas de Prata [3-pts]: ",p[i].nm);
        scanf("%d", &p[i].ms);
        printf("||\t \"%s\"  -  Medalhas de Bronze [1-pts]: ",p[i].nm);
        scanf("%d", &p[i].mb);

        //Establishment of total of points and the point addition/deduction system
        p[i].pts=pontuacao(p[i].mg,p[i].ms,p[i].mb);
        do
        {
            cont=0;
            printf("||\t \"%s\"  -  Houve adição de pontos? [S-sim/N-não]: ",p[i].nm);
            scanf(" %c", &pen);
            if(pen == 's' || pen== 'S' || pen== 'Y' || pen== 'y')
            {
                printf("|||\t \"%s\"  -  Bonificação de pontos: ",p[i].nm);
                scanf("%d", &sum);
                p[i].pts=p[i].pts+sum;
                cont=1;
            }
            else if(pen == 'n' || pen== 'N')
            {
                cont=1;
            }
            else
            {
                printf("Opção inválida. Digite novamente.\n\n");
                cont=0;
            }
        } 
        while (cont==0);
        do
        {
            cont=0;
            printf("||\t \"%s\"  -  Houve penalização de pontos? [S-sim/N-não]: ",p[i].nm);
            scanf(" %c", &pen);
            if(pen == 's' || pen== 'S' || pen== 'Y' || pen== 'y')
            {
                printf("|||\t \"%s\"  -  Redução de pontos: ",p[i].nm);
                scanf("%d", &red);
                p[i].pts=p[i].pts-red;
                cont=1;
            }
            else if(pen == 'n' || pen== 'N')
            {
                cont=1;
            }
            else
            {
                printf("Opção inválida. Digite novamente.\n\n");
                cont=0;
            }
        } 
        while (cont==0);
        
        printf("\n==================================================================================\n");
    }
    
    //Establishment of the ranking system
    ord(p,np);

    printf("\n\n\n");
    printf("\t\t\tTabela\n==================================================================================\n");
    printf("Nº|\t\t\tPaís\t\t\t|Ouro\tPrata\tBronze\tPts\n");
    for(i=0;i<np;i+=1)
    {
        //      Nº|\t\Country\t\t\tGold\tSilver\tBronze\tPts\n
        //      Nº|\t\tPaís\t\t\tOuro\tPrata\tBronze\tPts\n
        printf("%dº-\t\t%s",i+1,p[i].nm);
        distchar(p[i].nm);
        printf(" %d\t%d\t%d\t%d\n",p[i].mg,p[i].ms,p[i].mb,p[i].pts);
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

void distchar(char ct[TT])
{
    int tamc;
    tamc=strlen(ct);
    if(tamc<8) printf("\t\t\t\t");
    else if(tamc<=15) printf("\t\t\t");
    else if(tamc<=22) printf("\t\t");
    else if(tamc<=29) printf("\t");
    
}

void ord(struct pais *p, int np)
{
	struct pais mc;
	int i,j;
    for(i=0;i<np;i+=1)
    {
        for(j=i+1;j<np;j+=1)
        {
            if(p[j].mg>p[i].mg)
            {
                mc=p[j];
                p[j]=p[i];
                p[i]=mc;           
            }  
            else if(p[j].mg==p[i].mg && p[j].ms>p[i].ms)
            {
                mc=p[j];
                p[j]=p[i];
                p[i]=mc;
            }
            else if(p[j].mg==p[i].mg && p[j].ms==p[i].ms && p[j].mb>p[i].mb)
            {
                mc=p[j];
                p[j]=p[i];
                p[i]=mc;
            }
            else if(p[j].mg==p[i].mg && p[j].ms==p[i].ms && p[j].mb==p[i].mb && p[j].pts>p[i].pts)
            {
                mc=p[j];
                p[j]=p[i];
                p[i]=mc;
            }
        }
    }    
}