
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

double f(double x);
int MethodChord(double x);
int main()
{

    double  x1,x2,x,E,start,finish,sum;
    int Method,Mod, V,N,d=0,i=0,T=0;

    setlocale(LC_ALL, "Rus");


    printf("������ ���� �����ii:");
    scanf("%lf",&x1);
    printf("����� ���� �������:");
    scanf("%lf",&x2);
    printf("�������: ");
    scanf("%lf",&E);
    printf("��������� �i������i i�����i�:");
    scanf("%d",&N);
    if (f(x1)<0 && f(x2)>0)
    {
    printf("����� ������:\n\t1| ����� �i������\n\t2|����������� �����\n");
    scanf("%d",&Mod);
    printf("����� ���������� ���������\n\t1|����� ����\n\t2| ����� ����������� �i�����\n");
    scanf("%d",&Method);

    switch(Mod){
        case 1:
        {
            if(Method==1)
            {
                do{
                    start=clock();
                    T+=1;
                    x=(f(x2)*x1-f(x1)*x2)/(f(x2)-f(x1));
                    if(f(x)>0)
                        x1=x;
                    else
                        x2=x;

                    printf("T = %d\n",T);
                    printf("x = %lf\n",x);
                    printf("F(x) = %.2lf\n",f(x));
                     printf("\n            \n",f(x));
                    if(i==N){
                    finish=clock();
                    sum+=(finish-start)/CLK_TCK;
                    getch();
                    }
                }while(fabs(f(x))>E);

            }
            if(Method==2)
            {
                do{
                    start=clock();
                    T+=1;
                    x=(x1+x2)/2;
                    if((f(x)*f(x2))<0)
                        x1=x;
                    else
                        x2=x;

                    printf("T = %d\n",T);
                    printf("x = %2.lf\n",x);
                    printf("F(x) = %.2lf\n",f(x));
                    printf("\n            \n",f(x));
                    if(i==N){
                    finish=clock();
                    sum+=(finish-start)/CLK_TCK;
                    getch();
                    }
                }while((fabs(f(x1)-f(x2)))>E);
            }
            break;
        }
        case 2:
        { d=N;
            if(Method==1)
            {
                do{
                    start=clock();
                    x=(f(x2)*x1-f(x1)*x2)/(f(x2)-f(x1));
                    if(f(x)>0)
                        x1=x;
                    else
                        x2=x;
                    i+=1;
                    T=i;
                    if((i%N==0)&&(V!=3))
                    {
printf("��������� ������ �i���i��� i������i�...T= %d\nF(x)>E\tF(x) = %lf | E = %lf\n\t1|���������� � �i��� �i���i��� i������i�\n\t2|�������� ���i��\n\t3|������ ���i�� � ������������� �����i\n",T ,f(x),E);
                        finish=clock();
                        sum+=(finish-start)/CLK_TCK;
                        scanf("%d",&V);
                        switch(V)
                        {
                            case 1:
                            {
                                N+=d;
                                break;
                            }
                            case 2:
                            {
                                goto stop;
                            }
                        }
                    }
                }while(fabs(f(x))>E);
            }
            if(Method==2)
            {
                do{
                    start=clock();
                    x=(x1+x2)/2;
                    if((f(x)*f(x2))<0)
                        x1=x;
                    else
                        x2=x;
                    i+=1;
                    T=i;
                    if((i%N==0)&&(V!=3))
                    {
                        printf("��������� ������ �i���i��� i��������...T= %d\nF(x)>E\tF(x) = %lf | E = %lf\n\t1|���������� � �i��� �i���i��� i������i�\n\t2|�������� ���i��\n\t3|������ ���i�� � ������������� �����i\n",T ,fabs(x1-x2), E);
                        finish=clock();
                        sum+=(finish-start)/CLK_TCK;
                        scanf("%d",&V);
                        switch(V)
                        {
                            case 1:
                            {
                              N+=d;
                              break;
                            }
                            case 2:
                            {
                                goto stop;
                            }
                        }
                    }
                }while((fabs(f(x1)-f(x2)))>E&&(i<N));
            }
            break;
        }
    }
    stop:printf("x = %2.lf",x);
    printf("\n\n ��� ���� ��� ������� ���i��  %.2Lf sec.\n",sum);
    printf("T = %d",T);
    return 0;
    }
 else {
 printf("\n\n ��������� ������ ���i��\n");
}
}
double f(double x)
{
    return(((3-x)*(3-x)*(3-x))-3*x);
}
