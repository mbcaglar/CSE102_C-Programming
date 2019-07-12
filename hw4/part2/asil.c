/*M.BEDIRHAN ÇAĞLAR 23.032016
Bu program taylor serisine göre sinx ve cosx i hesaplamaktadır.*/
#include <stdio.h>
#define PI 3.14
void getInputs(int* degree,int* n,int* exit);
double sine(int degree,int n);
double cosine(int degree,int n);
int isaret(int n); /*negatif yada pozitifliği ne göre kontrol eder.*/
double x_ustAl(double x,int n);/*sin için üst alma fonksiyonu*/
double x_ustAl2(double x,int n);/*cos için üst alma fonksiyonu*/
int faktoriyel(int n);/*sin için faktoriyel fonksiyonum*/
int faktoriyel2(int n);/*cos için faktoriyel fonksiyonum*/
int main()
{
	int degree=0;
	int n=0;
	int a=69;
	getInputs(&degree,&n,&a);
}
void getInputs(int*degree,int* n,int* exit)
{	
   int p;
   char cikis;
    *exit=0;
    p=scanf("%d",degree);
    if(*degree==0)
        *exit=0;
    if(p==0)
    {
        scanf(" %c",&cikis);
        if(cikis=='E' || cikis=='e')
            *exit=1;
        else
            *exit=0;
    }
	scanf("%d",n);
	while(*exit!=1)	    	
{	
		printf("sin(%d) where n is %d = %.4f\n",*degree,*n,sine(*degree,*n));
		printf("cos(%d) where n is %d = %.4f\n",*degree,*n,cosine(*degree,*n));
		p=scanf("%d",degree);
		if(*degree==0)
		    *exit=0;
		if(p==0)
		{
		    scanf(" %c",&cikis);
		    if(cikis=='E' || cikis=='e')
			{		     
			   *exit=1;
					    
			}			
			else
		        *exit=0;
		}
		scanf("%d",n);	
}
}
double sine(int degree,int n)
{
    double x,total;
    double sonuc;
	degree=degree%360;	
	x= ((double)degree/360)*2*PI;
	total=0;
	while(n>=0)
	{
	    sonuc=(isaret(n)*x_ustAl(x,n))/faktoriyel(n);
	    total=sonuc+total;
	    n--;
	    
	}
	return total;
}

double cosine(int degree,int n)
{
    double x,total;
	double sonuc;
	degree=degree%360;
	x=((double)degree/360)*2*PI;
	total=0;
	while(n>=0)
	{
	    sonuc=(isaret(n)*x_ustAl2(x,n))/faktoriyel2(n);
	    total=sonuc+total;
	    n--;
	    
	}	
    return total;
}

int isaret(int n)
{
	if(n%2==0)
		return 1;
	else
		return -1;
}
double x_ustAl(double x,int n)
{
	double sonuc=1;
	int i;
	for(i=1; i<=2*n+1; i++)
	{
		sonuc*=x;
	}	
	return sonuc;
}
int faktoriyel(int n)
{
	int i;
	int carpim=1;
	for(i=1; i<=2*n+1; i++)
	{
		carpim*=i;
	}	
	return carpim;
}
double x_ustAl2(double x,int n)
{
	
	double sonuc=1;
	int i;
	for(i=1; i<=2*n; i++)
	{
		sonuc*=x;
	}	
	return sonuc;
}

int faktoriyel2(int n)
{
	int i;
	int carpim=1;
	for(i=1; i<=2*n; i++)
	{
		carpim*=i;
	}	
	return carpim;
}
