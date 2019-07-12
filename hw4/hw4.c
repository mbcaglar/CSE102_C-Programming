#include <stdio.h>
#define PI 3.14
void getInputs(int* degree,int* n,int* exit);
double sine(int degree,int n);
double cose(int degree,int n);
int isaret(int n);
double x_ustAl(double x,int n);
double x_ustAl2(double x,int n);
int faktoriyel(int n);
int faktoriyel2(int n);
int main()
{
	int degree;
	int n;
	int a=69;
	scanf("%d",&degree);
	scanf("%d",&n);	
	getInputs(&degree,&n,&a);	
}
void getInputs(int*degree,int* n,int* exit)
{	
	double taylorSin_x=0;
	double taylorCos_x=0;
	int n1,kontrol;
	int bitir=69;	
	while((int)kontrol!=bitir)		
	{	
		n1=*n;
		n1--;
		while(n1>=0)
		{	
			taylorSin_x+=sine(*degree,n1);
			taylorCos_x+=cose(*degree,n1);		
			n1--;
		}
		printf("sin(%d) where n is %d = %.4f\n",*degree,*n,taylorSin_x);
		printf("cos(%d) where n is %d = %.4f\n",*degree,*n,taylorCos_x);
		
		scanf("%d",degree);
		kontrol=*degree;
		if((int)kontrol!=bitir)
		{			
			scanf("%d",n);
	
			taylorSin_x=0;
			taylorCos_x=0;	
		}
	}
}
double sine(int degree,int n)
{
	degree=degree%360;	
	double x= ((double)degree/360)*2*PI;
	double sinX;
	sinX=(isaret(n)*x_ustAl(x,n))/faktoriyel(n);
	return sinX;
}

double cose(int degree,int n)
{
	degree=degree%360;
	double x=((double)degree/360)*2*PI;
	double cosX;
	cosX=(isaret(n)*x_ustAl2(x,n)/faktoriyel2(n));
	
return cosX;

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
