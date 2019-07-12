#include <stdio.h>
#include <math.h>
void instruction();
void positive(int num);
void property(int section,int num);	
int main()
{
	int num;
	instruction();
	positive(num);

}

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

}
void positive(int num){
	char yOrn;	
	int section;
	printf("Please enter a positive integer: ");
	scanf("%d",&num);
	if(num<=0){
		printf("The entered number is not positive\n");
		printf("Do you want to continue (y/n)? ");
		scanf(" %c",&yOrn);
}		
		if(yOrn =='y')
			positive(num);
		else if(yOrn =='n')
			printf("Good bye  !\n");		
	
	else{ 
		printf("Which property would you like to check ?\n");
		printf("1)Odd number\n");
		printf("2)Factorial number\n");
		printf("3)Narcissistic number\n");
		printf("PLease enter the (1/2/3): "); 
		scanf("%d",&section);
		property(section,num);		
		
}
}
void property(int section,int num){
	char yOrn;
	int count;
	int i;
	int narcis;
	int digit1,digit2,digit3,digit4;

	switch(section){
	case 1: if(num%2==0)
				printf("%d is not an odd number\n",num); 
			else
				 printf("%d is an odd number\n",num);		
			 printf("Do you want to continue (y/n)? ");
			 scanf(" %c",&yOrn);

			 if(yOrn =='y')
					positive(num);
			 else if(yOrn =='n')
					printf("Good bye  !\n"); break;
	case 2: count=1;
			for(i=1; i<=num; i+=1)
{
				if(num%i==0)
					count=count*i;			
				
				else if(num%i!=0)
					break;	
}				if(num==count)
					printf("%d is a factorial number\n",num);
				else 
					printf("%d is not a factorial number\n",num); 	
				
			    printf("Do you want to continue (y/n)? ");
			 	scanf(" %c",&yOrn);

			 	if(yOrn =='y')
					positive(num);
			 	else if(yOrn =='n')
					printf("Good bye  !\n"); break;	
	case 3:	if(num<10)	
				printf("%d is a narcissistic number\n",num);
			else if(num<100){
				digit1 = num/10 ;
				digit2 = num%10 ;
				narcis =pow(digit1,2)+pow(digit2,2);
				if(num==narcis)
					printf("%d is a narcissistic number\n",num);
				else printf("%d is not a narcissistic number\n",num);
}			
			else if(num<1000){
				digit1 = num/100 ;
				digit2 = (num%100)/10 ;
				digit3 = num%10 ;
				narcis =pow(digit1,3)+pow(digit2,3)+pow(digit3,3);
				if(num==narcis)
					printf("%d is a narcissistic number\n",num);
				else printf("%d is not a narcissistic number\n",num);
}			
			else if(num<10000){
				digit1 = num/1000 ;
				digit2 = (num%1000)/100 ;
				digit3 = num%100 ;
				digit4 = num%10 ;
				narcis =pow(digit1,4)+pow(digit2,4)+pow(digit3,4)+pow(digit4,4);
				if(num==narcis)
					printf("%d is a narcissistic number\n",num);
				else printf("%d is not a narcissistic number\n",num);
			
}			
				printf("Do you want to continue (y/n)? ");
			 scanf(" %c",&yOrn);

			 if(yOrn =='y')
					positive(num);
			 else if(yOrn =='n')
					printf("Good bye  !\n");break;			
}
}
