/*M.Bedirhan ÇAĞLAR 141044073
//07.03.2016//
Bu program girilen pozitif bir sayının tekliğini,faktoriyelliğini ve nacissistic
olup olmadığını seçenekler ve yönlendirmeler ile kontrol eder.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
 
void instruction();
void menu();
void property(int section,int num);
int preferQuestions();
int odd(int num);
int faktoriyel(int num);
int narcissistic(int num);

int main()
{
	int num,section;
	instruction();	
	do{
		printf("Please enter a positive integer: ");
		scanf("%d",&num);
		if(num>0){
			menu();
			printf("PLease enter the (1/2/3): "); 
			scanf("%d",&section);
			property(section,num);
}
		else
			printf("The entered number is not positive\n");

}	while(preferQuestions());
		
	printf("Good Bye !\n");
	return 0;
}
/* instruction giriş tablosu ve bilgilendirme fonksiyonudur.
*/
void instruction(){
	int i;	
	for(i=0; i<60; i+=1)
		printf("*");
	printf("\n*                   WELCOME !                              *");
	printf("\n*	 This program checks whether the given number      *");
	printf("\n*	is an odd, a factorial or a narcissistic number    *\n");
	printf("*                                                          *\n");
	for(i=0; i<60; i+=1)
		printf("*");
	printf("\n");
	
	return;
}
/*property fonksiyonum girilen sayının hangi özelliğinin kontrol edileceğini 
seçenekler doğrultusunda söyler.Her bir seçenek için fonksiyon çağırır.
*/
void property(int section,int num){
	switch(section){
	case 1: if(odd(num))
				printf("%d is an odd number\n",num);
			else
				printf("%d is not an odd number\n",num); break;			 
	case 2: if(faktoriyel(num))
				printf("%d is a factorial number\n",num);
			else 
				printf("%d is not a factorial number\n",num);  break;			
					
	case 3:	if(narcissistic(num))
				printf("%d is an narcissistic number\n",num);			
			else
				printf("%d is not an narcissistic number\n",num); break;
	default:printf("Yanlış bir giriş yaptınız.\n"); break;
}
	return;
}

/* preferQuestions fonksiyonum usera devam edip etmek istemediğini sormaktadır.
Userın cevabı 'y' yani yes ise TRUE (1)'i return ederken 'n' yani no ise FALSE
(0)'ı return eder. 
*/
int preferQuestions(){
	char yOrn;
	int num;	
	printf("Do you want to continue (y/n)? ");
	scanf(" %c",&yOrn);
	if(yOrn =='y')
		return TRUE;
	else if(yOrn =='n')
		return FALSE;
	return 0;
}

/* odd fonksiyonum girilen sayı ikiye bölünüyorsa FALSE yani 0 değeri 
döndürmektedir.Ikiye bölünmüyorsa TRUE yani 1 değerini return etmektedir.
*/
int odd(int num){
	if(num%2==0)
		return FALSE;	 
	else		
		return TRUE;
}

/* faktoriyel fonksiyonum parametre olarak numberı aldıktan sonra for döngüsüne
girerek sayının 1 den itibaren bölenlerini bulur ta ki ilk bölünmeyen sayıya
kadar.sonra fordan çıkarak bölünen sayıları çarpar ve çarpım sayının kendisine 
eşitse fonksiyon 1'i return eder,değilse 0'ı return eder.
*/
int faktoriyel(int num){
			int count,i;			
			count=1;
			for(i=1; i<=num; i+=1)
{
				if(num%i==0)
					count=count*i;			
				
				else if(num%i!=0)
					i=num*num;/* amaç döngüyü sonlandırmak için loop conditionı
								bozmaktır(break,exit komutlarını 
								kullanamadığımız için)*/ 		
}				if(num==count)
					return TRUE;
				else 
					return FALSE;
}

/* narcissistic fonksiyonum ise önce girilen sayının basamak sayısını while 
döngüsünde sayı büyüktür 0 olana kadar yapar ancak sayı her bir dönmede 10 a 
bölünürek basamak bulunur.Daha sonra sayı değişkeni while da değiştiği için 
tekrar num değişkeni sayıya atanarak for içinde basamaktaki sayı değerlerini her
 birini önce basamak sayısının 10^basamak-1 ine bölünerek ilk digitten itibaren 
sayı değerlerini bulup ana sayıdan çıkarıp bi sonraki digiti bularak elde eder.
Ve en sonda deger değişkeni ile her bir sayı değeri değişkenini basamak sayısına
göre üst alıp toplayarak ana sayıya eşit olup olmadığını kontrol eder eşitse
return (TRUE) 1'i değilse return (FALSE) 0'ı döner.
*/ 
int narcissistic(int num){
	int narcis,basamak;
	int i,deger,sayi;	
	sayi=num;
	narcis = 0;
	basamak = 0;
	while(sayi>0){
		basamak++;
		sayi/=10;
	}
	
	sayi = num;
	for(i=0; basamak>0; ++i){
		deger = sayi/pow(10,basamak-1);
		if(sayi>10)	
			sayi = sayi-deger*pow(10,basamak-1);
		narcis+=pow(deger,basamak+i);
		basamak--;
	}

	if(narcis==num)
		return TRUE;
	else
		return FALSE;
}
/*pozitif sayılar için açılan menu seçeneğidir.
*/
void menu(){
		printf("Which property would you like to check ?\n");
		printf("1)Odd number\n");
		printf("2)Factorial number\n");
		printf("3)Narcissistic number\n");
		
		return;
}
