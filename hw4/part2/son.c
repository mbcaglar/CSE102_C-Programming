/*M.Bedirhan ÇAĞLAR 23.03.2016
Bu program number borderwidth ve chr şekli için parametreler alarak girilen 
sayıyı çerçeve içinde istediğiniz karakter ile yazmaktadır.Ayrıca bu işlem 
negatif sayı ile 99999 dan büyük sayı girene kadar devam etmektedir.*/
#include <stdio.h>
#include <math.h>
void getInputs(int *num,int *borderWidth,char *chr);
int printNumber(int num,int borderWidth,char chr);
int main()
{
	int num;
	char chr;
	int borderWidth;
	getInputs(&num,&borderWidth,&chr);
	return 0;
}
void getInputs(int *num,int *borderWidth,char *chr)//userdan parametreleri alır.
{									
	int number;
	scanf("%d",num);
	number=*num;
	if(number>=0 && number<=99999)
	{
		scanf("%d",borderWidth);
		scanf(" %c",chr);	
	}	
	while(number>=0 && number<=99999)	
	{
		printNumber(number,*borderWidth,*chr);	
		scanf("%d",num);	
		number=*num;
		if(number>=0 && number<=99999)
		{
			scanf("%d",borderWidth);
			scanf(" %c",chr);	
		}	
		
	}
	return;
	
}
/*printNumber fonksiyonu önce girilen sayıyı basamaklarına ayırarak değerlerini
bulur sonra bunları yazdırmak için satır satır olan sayıların satırlarını basar.
*/
int printNumber(int num,int borderWidth,char chr)
{
	int basamak,bas;//bas değişkeni basamak sayısını kullandıktan sonra eski
					//haline döndürmek için kullanılır.	
	int i,deger,sayi;	
	int j,k,cizim;
	int b;//bu da borderi eski haline çevirmek için kullanılır.	
	int deger1,deger2,deger3,deger4,deger5,deger6;	
	sayi=num;
	basamak = 0;
	b=borderWidth;
	if(sayi!=0)
	{	
		while(sayi>0)
		{
			basamak++;
			sayi/=10;
		}
	
	}
	else
	{
		basamak=1;
	}
	bas=basamak;
	sayi = num;
	/* bu sayıların ilk değerlerini 10 a atamamın nedeni aşağıda satır satır 
	basarken rakam olmasa bile 0 atıyor ve 0 ı basıyor bu atama sayesinde ise
	olmayan rakamı basamıycak.*/
	deger1=10;
	deger2=10;
	deger3=10;
	deger4=10;
	deger5=10;
	deger6=10;	
	for(i=0; basamak>0; ++i)
	{
		deger = sayi/pow(10,basamak-1);		
		if(sayi>10 || deger==0)	
		{	
			sayi = sayi-deger*pow(10,basamak-1);
			if(i==0)
			{
				deger1=deger;	
			}
			else if(i==1)
			{
				deger2=deger;
			}
			else if(i==2)
			{
				deger3=deger;
			}
			else if(i==3)
			{
				deger4=deger;
			}		
			else if(i==4)
			{
				deger5=deger;
			}		
		}
		else{
				deger6=deger;		
							
			}	
		basamak--;
	}	
	borderWidth=b;
	basamak=bas;
	/*borderın en geniş çerçevesinin üstünü satır olarak bastırır.*/ 			
	while(borderWidth>0)
	{
		for(j=1; j<=basamak*7+2*b; j++)
		{
			printf("%c",chr);
		}		
	printf("\n");
	borderWidth--;
	}

	k=1;
	cizim=7;
	basamak=bas;	
	while(cizim>0)
{
		borderWidth=b;		
		while(borderWidth>0)
		{
			printf("%c",chr);
			borderWidth--;
		}
/*burdan itibaren satır satır çerçeve içi ve numberı basmaya başlar.*/
		if(k==1 || k==7)
		{
			for(j=1; j<=basamak*7; j++)
			{
				printf(" ");
			}		
			
		}			
	   if(k==2)
		{
			if(deger1==1)
			{
				printf("   %c   ",chr);
			}
			if(deger1==2 || deger1==3 || deger1==5 || deger1==6 || 
			deger1==7 || deger1==8 || deger1==9 || deger1==0)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger1==4)
			{
				printf("  %c %c  ",chr,chr);
			}
			if(deger2==1)
			{
				printf("   %c   ",chr);
			}
			if(deger2==2 || deger2==3 || deger2==5 || deger2==6 || 
			deger2==7 || deger2==8 || deger2==9 || deger2==0)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger2==4)
			{
				printf("  %c %c  ",chr,chr);
			}
			
			if(deger3==1)
			{
				printf("   %c   ",chr);
			}
			if(deger3==2 || deger3==3 || deger3==5 || deger3==6 || 
			deger3==7 || deger3==8 || deger3==9 || deger3==0)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger3==4)
			{
				printf("  %c %c  ",chr,chr);
			}
			if(deger4==1)
			{
				printf("   %c   ",chr);
			}
			if(deger4==2 || deger4==3 || deger4==5 || deger4==6 || 
			deger4==7 || deger4==8 || deger4==9 || deger4==0)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger4==4)
			{
				printf("  %c %c  ",chr,chr);
			}
			if(deger5==1)
			{
				printf("   %c   ",chr);
			}
			if(deger5==2 || deger5==3 || deger5==5 || deger5==6 || 
			deger5==7 || deger5==8 || deger5==9 || deger5==0)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger5==4)
			{
				printf("  %c %c  ",chr,chr);
			}
			if(deger6==1)
			{
				printf("   %c   ",chr);
			}
			if(deger6==2 || deger6==3 || deger6==5 || deger6==6 || 
			deger6==7 || deger6==8 || deger6==9 || deger6==0)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger6==4)
			{
				printf("  %c %c  ",chr,chr);
			}
	}
	else if(k==3)
		{
			if(deger1==1)
			{
				printf("  %c%c   ",chr,chr);
			}
			if(deger1==4 || deger1==8 || deger1==9 || deger1==0 )
			{
				printf("  %c %c  ",chr,chr);
			}
			if(deger1==2 || deger1==3 || deger1==7)
			{
				printf("    %c  ",chr);
			}
			if(deger1==5 || deger1==6)
			{
				printf("  %c    ",chr);
			}
			if(deger2==1)
			{
				printf("  %c%c   ",chr,chr);
			}
			if(deger2==4 || deger2==8 || deger2==9 || deger2==0 )
			{
				printf("  %c %c  ",chr,chr);
			}
			if(deger2==2 || deger2==3 || deger2==7)
			{
				printf("    %c  ",chr);
			}
			if(deger2==5 || deger2==6)
			{
				printf("  %c    ",chr);
			}
			
			if(deger3==1)
			{
				printf("  %c%c   ",chr,chr);
			}
			if(deger3==4 || deger3==8 || deger3==9 || deger3==0 )
			{
				printf("  %c %c  ",chr,chr);
			}
			if(deger3==2 || deger3==3 || deger3==7)
			{
				printf("    %c  ",chr);
			}
			if(deger3==5 || deger3==6)
			{
				printf("  %c    ",chr);
			}
			if(deger4==1)
			{
				printf("  %c%c   ",chr,chr);
			}
			if(deger4==4 || deger4==8 || deger4==9 || deger4==0 )
			{
				printf("  %c %c  ",chr,chr);
			}
			if(deger4==2 || deger4==3 || deger4==7)
			{
				printf("    %c  ",chr);
			}
			if(deger4==5 || deger4==6)
			{
				printf("  %c    ",chr);
			}
			if(deger5==1)
			{
				printf("  %c%c   ",chr,chr);
			}
			if(deger5==4 || deger5==8 || deger5==9 || deger5==0 )
			{
				printf("  %c %c  ",chr,chr);
			}
			if(deger5==2 || deger5==3 || deger5==7)
			{
				printf("    %c  ",chr);
			}
			if(deger5==5 || deger5==6)
			{
				printf("  %c    ",chr);
			}
			if(deger6==1)
			{
				printf("  %c%c   ",chr,chr);
			}
			if(deger6==4 || deger6==8 || deger6==9 || deger6==0 )
			{
				printf("  %c %c  ",chr,chr);
			}
			if(deger6==2 || deger6==3 || deger6==7)
			{
				printf("    %c  ",chr);
			}
			if(deger6==5 || deger6==6)
			{
				printf("  %c    ",chr);
			}

	}
	
	else if(k==4)
	{
			if(deger1==0)
			{
				printf("  %c %c  ",chr,chr);
			}			
			if(deger1==1)
			{
				printf("   %c   ",chr);
			}
			if(deger1==4 || deger1==8 || deger1==6 || deger1==5 || deger1==2 ||
			  deger1==9)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger1==3)
			{
				printf("   %c%c  ",chr,chr);
			}
			if(deger1==7)
			{
				
				printf("    %c  ",chr);
			}
			if(deger2==0)
			{
				printf("  %c %c  ",chr,chr);
			}			
			
			if(deger2==1)
			{
				printf("   %c   ",chr);
			}
			if(deger2==4 || deger2==8 || deger2==6 || deger2==5 || deger2==2 ||
			  deger2==9)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger2==3)
			{
				printf("   %c%c  ",chr,chr);
			}
			if(deger2==7)
			{
				
				printf("    %c  ",chr);
			}
			if(deger3==0)
			{
				printf("  %c %c  ",chr,chr);
			}			

			if(deger3==1)
			{
				printf("   %c   ",chr);
			}
			if(deger3==4 || deger3==8 || deger3==6 || deger3==5 || deger3==2 ||
			  deger3==9)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger3==3)
			{
				printf("   %c%c  ",chr,chr);
			}
			if(deger3==7)
			{
				
				printf("    %c  ",chr);
			}
			if(deger4==0)
			{
				printf("  %c %c  ",chr,chr);
			}			

			if(deger4==1)
			{
				printf("   %c   ",chr);
			}
			if(deger4==4 || deger4==8 || deger4==6 || deger4==5 || deger4==2 ||
			  deger4==9)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger4==3)
			{
				printf("   %c%c  ",chr,chr);
			}
			if(deger4==7)
			{
				
				printf("    %c  ",chr);
			}
			if(deger5==0)
			{
				printf("  %c %c  ",chr,chr);
			}			

			if(deger5==1)
			{
				printf("   %c   ",chr);
			}
			if(deger5==4 || deger5==8 || deger5==6 || deger5==5 || deger5==2 ||
			  deger5==9)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger5==3)
			{
				printf("   %c%c  ",chr,chr);
			}
			if(deger5==7)
			{
				
				printf("    %c  ",chr);
			}
			if(deger6==0)
			{
				printf("  %c %c  ",chr,chr);
			}			

			if(deger6==1)
			{
				printf("   %c   ",chr);
			}
			if(deger6==4 || deger6==8 || deger6==6 || deger6==5 || deger6==2 ||
			  deger6==9)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger6==3)
			{
				printf("   %c%c  ",chr,chr);
			}
			if(deger6==7)
			{
				
				printf("    %c  ",chr);
			}
	
	}
	else if(k==5)
	{
			if(deger1==1)
			{
				printf("   %c   ",chr);
			}
			if(deger1==4 || deger1==3 || deger1==7 || deger1==5 || deger1==9)
			{
				printf("    %c  ",chr);
			}
			if(deger1==2)
			{
				printf("  %c    ",chr);
			}
			if(deger1==0 || deger1==6 || deger1==8)
			{
				
				printf("  %c %c  ",chr,chr);
			}
			if(deger2==1)
			{
				printf("   %c   ",chr);
			}
			if(deger2==4 || deger2==3 || deger2==7 || deger2==5 || deger2==9)
			{
				printf("    %c  ",chr);
			}
			if(deger2==2)
			{
				printf("  %c    ",chr);
			}
			if(deger2==0 || deger2==6 || deger2==8)
			{
				
				printf("  %c %c  ",chr,chr);
			}
			if(deger3==1)
			{
				printf("   %c   ",chr);
			}
			if(deger3==4 || deger3==3 || deger3==7 || deger3==5 || deger3==9)
			{
				printf("    %c  ",chr);
			}
			if(deger3==2)
			{
				printf("  %c    ",chr);
			}
			if(deger3==0 || deger3==6 || deger3==8)
			{
				
				printf("  %c %c  ",chr,chr);
			}
			if(deger4==1)
			{
				printf("   %c   ",chr);
			}
			if(deger4==4 || deger4==3 || deger4==7 || deger4==5 || deger4==9)
			{
				printf("    %c  ",chr);
			}
			if(deger4==2)
			{
				printf("  %c    ",chr);
			}
			if(deger4==0 || deger4==6 || deger4==8)
			{
				
				printf("  %c %c  ",chr,chr);
			}
			if(deger5==1)
			{
				printf("   %c   ",chr);
			}
			if(deger5==4 || deger5==3 || deger5==7 || deger5==5 || deger5==9)
			{
				printf("    %c  ",chr);
			}
			if(deger5==2)
			{
				printf("  %c    ",chr);
			}
			if(deger5==0 || deger5==6 || deger5==8)
			{
				
				printf("  %c %c  ",chr,chr);
			}
			if(deger6==1)
			{
				printf("   %c   ",chr);
			}
			if(deger6==4 || deger6==3 || deger6==7 || deger6==5 || deger6==9)
			{
				printf("    %c  ",chr);
			}
			if(deger6==2)
			{
				printf("  %c    ",chr);
			}
			if(deger6==0 || deger6==6 || deger6==8)
			{
				
				printf("  %c %c  ",chr,chr);
			}

	}
	else if(k==6)
	{	
			if(deger1==4 || deger1==7)
			{
				printf("    %c  ",chr);
			}
			if(deger1==1 || deger1==2 || deger1==3 || deger1==5 || deger1==6)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}

			if(deger1==0 || deger1==9 || deger1==8)
			{
				
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger2==4 || deger2==7)
			{
				printf("    %c  ",chr);
			}
			if(deger2==1 || deger2==2 || deger2==3 || deger2==5 || deger2==6)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}

			if(deger2==0 || deger2==9 || deger2==8)
			{
				
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger3==4 || deger3==7)
			{
				printf("    %c  ",chr);
			}
			if(deger3==1 || deger3==2 || deger3==3 || deger3==5 || deger3==6)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}

			if(deger3==0 || deger3==9 || deger3==8)
			{
				
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger4==4 || deger4==7)
			{
				printf("    %c  ",chr);
			}
			if(deger4==1 || deger4==2 || deger4==3 || deger4==5 || deger4==6)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}

			if(deger4==0 || deger4==9 || deger4==8)
			{
				
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger5==4 || deger5==7)
			{
				printf("    %c  ",chr);
			}
			if(deger5==1 || deger5==2 || deger5==3 || deger5==5 || deger5==6)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}

			if(deger5==0 || deger5==9 || deger5==8)
			{
				
				printf("  %c%c%c  ",chr,chr,chr);
			}
			if(deger6==4 || deger6==7)
			{
				printf("    %c  ",chr);
			}
			if(deger6==1 || deger6==2 || deger6==3 || deger6==5 || deger6==6)
			{
				printf("  %c%c%c  ",chr,chr,chr);
			}

			if(deger6==0 || deger6==9 || deger6==8)
			{
				
				printf("  %c%c%c  ",chr,chr,chr);
			}

		}
					
		borderWidth=b;	
		while(borderWidth>0)
		{
			printf("%c",chr);
			borderWidth--;
		}
		printf("\n");
		cizim--;
		k++;				
	}
	borderWidth=b;
	basamak=bas;
	while(borderWidth>0)
		{
			for(j=1; j<=basamak*7+2*b; j++)
			{
				printf("%c",chr);
			}		
				printf("\n");
				borderWidth--;
		}
		
	return 0;

}






















