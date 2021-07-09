#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

main()
{
    setlocale(LC_ALL,"portuguese");
    //Declaração de variáveis independentes
    int N,W,maiorp,maiorv,maiorin, Wf=0,vf=0;
    float maiorvp;    

    //Obtenção de primeiros valores (Números de itens)    (Capacidade da mochila)
    printf("Digite dois números um representando o número de itens para serem levados na viagem e outro a capacidade da mochila\n");
    scanf("%d%d", &N, &W);

    //Declaração de variáveis dependentes
    int p[N],v[N],in[N];
    float vp[N];

    //Obtenção dos pesos dos itens 
    printf("Digite os pesos dos itens que serão levados\n");
    for(int i = 0; i < N; i++)
    {
        printf("%d: ",i+1);
        scanf("%d", &p[i]);
    }

    //Obtenção dos valores dos itens 
    printf("Digite os valores dos itens que serão levados\n");
    for(int i = 0; i < N; i++)
    {
        printf("%d: ",i+1);
        scanf("%d", &v[i]);
    }

    //Obtenção da razão entre o valor e o peso
    for(int i = 0;i < N; i++)
    {
        vp[i]= v[i]/(float)p[i];
    }
    
    //Ordenamento das localizações de vetores com base na maior razão
    for(int i = 0;i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(vp[j]>vp[i] &&  j>i)
            {
                maiorp = p[j];
                p[j] = p[i];
                p[i] = maiorp;
                maiorv = v[j];
                v[j] = v[i];
                v[i] = maiorv;
                maiorvp = vp[j];
                vp[j] = vp[i];
                vp[i] = maiorvp;
            }
            else if (vp[j]==vp[i] && j>i && p[j]<p[i])
            {
                maiorp = p[j];
                p[j] = p[i];
                p[i] = maiorp;
                maiorv = v[j];
                v[j] = v[i];
                v[i] = maiorv;
                maiorvp = vp[j];
                vp[j] = vp[i];
                vp[i] = maiorvp; 
            }
        }
    }

    //Escalamento da mochila
    for(int i = 0;i < N; i++)
    {
        if (W>=(Wf + p[i]))
        {
            Wf+=p[i];
            vf+=v[i];
            in[i]=1;
        }
        else
        {
            in[i]=0;
        }
    }


    //Ordenamento das localizações de vetores com base no maior peso
    for(int i = 0;i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(p[j]>p[i] &&  j>i)
            {
                maiorp = p[j];
                p[j] = p[i];
                p[i] = maiorp;
                maiorv = v[j];
                v[j] = v[i];
                v[i] = maiorv;
                maiorvp = vp[j];
                vp[j] = vp[i];
                vp[i] = maiorvp;
                maiorin = in[j];
                in[j] = in[i];
                in[i] = maiorin;
            }
        }
    }

    //Escala todos os itens
    printf("\n================================================================\n");
    printf("Escala de todos os itens sugeridos\n");
    printf("Item:\tValor\tPeso\tValor/Peso\t Aceito?[1 = sim]\n");
    for(int i = 0;i < N; i++)
    {
        printf("%d :\t\"%d\"\t%dg\t%0.2f\t\t\t%d\n", i+1,v[i],p[i],vp[i],in[i]);
    }

    //Escala total da mochila
    printf("\n================================================================\nEscala dos itens da mochila\n");
    printf("Item:\tValor\tPeso\tValor/Peso\n");
    for(int i = 0;i < N; i++)
    {
        if(in[i]==1)
        {
            printf("%d :\t\"%d\"\t%dg\t%0.2f\n", i+1,v[i],p[i],vp[i]);
        }
    }

    //Declaração da resposta
    printf("\n================================================================\n");
    printf("\nResposta final\n\nSoma dos valores dos objetos colocados:\t%d\nSoma dos pesos dos objetos colocados:\t%d\n\n",vf,Wf);
}