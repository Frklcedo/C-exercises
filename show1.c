#include<stdio.h>

float tempus(int s, float v);
float space(float v, int t);
float celerm(int s, int t);

main()
{
    int dist_a_b,t_b_c,dist_b_c,t_show;
    float vel_t1,vel_t2;
    printf("Digite a distancia da cidade A para a cidade B (km)\n");
    scanf("%d",&dist_a_b);
    printf("Digite a velocidade do primeiro trem (km/h)\n");
    scanf("%f",&vel_t1);
    printf("Digite quanto tempo falta para o trem para a cidade C sair (minutos)\n");
    scanf("%d",&t_b_c);
    printf("Digite a distancia da cidade B para a cidade C (km)\n");
    scanf("%d",&dist_b_c);
    printf("Digite a velocidade do segundo trem (km/h)\n");
    scanf("%f",&vel_t2);
    printf("Digite quanto tempo falta para começar o show (minutos)\n");
    scanf("%d",&t_show);

    printf("\n\nVoce conseguira chegar antes do show começar?\n");
    if(t_b_c < tempus(dist_a_b,vel_t1))
    {
        printf("False\n");
    }
    else
    {
        if(t_show < t_b_c+tempus(dist_b_c,vel_t2))
        {
            printf("False\n");
        } 
        else
        {
            printf("True\n");
        }
    }

}

float tempus(int s, float v)
{
    float t;
    t = 60*s/v;
    return t;
}

float space(float v, int t)
{
    float s;
    s = v*t/60;
    return s;
}

float celerm(int s, int t)
{
    float v;
    v = s/(float)t/60;
    return v;
}