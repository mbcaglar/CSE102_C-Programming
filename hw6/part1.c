#include <stdio.h>
#include <string.h>
#define TRUE 1
void freq(char *str,int *fr);
int main()
{
	int fr[37];
	int i,size;
	
	int count=0;
	freq("ABCDEFGHIJKLMNOPQRSTUVYZ0123456789 ???",fr);		

	return 0;
}
void freq(char *str,int *fr)
{
	int i,size;
	size=strlen(str);
	for(i=0; i<size; i++)
	{
		fr[i]=0;
	}
	for(i=0; i<size; i++)
	{
		if(str[i]=='a' || str[i]=='A')
			fr[0]+=1;
		
		else if(str[i]=='b' || str[i]=='B')
			fr[1]+=1;
 
		else if(str[i]=='c' || str[i]=='C')
			fr[2]+=1; 

		else if(str[i]=='d' || str[i]=='D')
			fr[3]+=1;
 
		else if(str[i]=='e' || str[i]=='E')
			fr[4]+=1; 

		else if(str[i]=='f' || str[i]=='F')
			fr[5]+=1; 

		else if(str[i]=='g' || str[i]=='G')
			fr[6]+=1; 

		else if(str[i]=='h' || str[i]=='H')
			fr[7]+=1; 

		else if(str[i]=='i' || str[i]=='I')
			fr[8]+=1; 

		else if(str[i]=='j' || str[i]=='J')
			fr[9]+=1; 

		else if(str[i]=='k' || str[i]=='K')
			fr[10]+=1; 

		else if(str[i]=='l' || str[i]=='L')
			fr[11]+=1; 

		else if(str[i]=='m' || str[i]=='M')
			fr[12]+=1; 

		else if(str[i]=='n' || str[i]=='N')
			fr[13]+=1; 

		else if(str[i]=='o' || str[i]=='O')
			fr[14]+=1; 

		else if(str[i]=='p' || str[i]=='P')
			fr[15]+=1; 

		else if(str[i]=='q' || str[i]=='Q')
			fr[16]+=1; 

		else if(str[i]=='r' || str[i]=='R')
			fr[17]+=1; 

		else if(str[i]=='s' || str[i]=='S')
			fr[18]+=1; 

		else if(str[i]=='t' || str[i]=='T')
			fr[19]+=1; 

		else if(str[i]=='u' || str[i]=='U')
			fr[20]+=1; 

		else if(str[i]=='v' || str[i]=='V')
			fr[21]+=1; 

		else if(str[i]=='w' || str[i]=='W')
			fr[22]+=1; 

		else if(str[i]=='x' || str[i]=='X')
			fr[23]+=1; 

		else if(str[i]=='y' || str[i]=='Y')
			fr[24]+=1; 

		else if(str[i]=='z' || str[i]=='Z')
			fr[25]+=1; 

		else if(str[i]=='0')
			fr[26]+=1; 

		else if(str[i]=='1')
			fr[27]+=1; 

		else if(str[i]=='2')
			fr[28]+=1; 

		else if(str[i]=='3')
			fr[29]+=1; 

		else if(str[i]=='4')
			fr[30]+=1; 

		else if(str[i]=='5')
			fr[31]+=1; 

		else if(str[i]=='6')
			fr[32]+=1; 

		else if(str[i]=='7')
			fr[33]+=1; 

		else if(str[i]=='8')
			fr[34]+=1; 

		else if(str[i]=='9')
			fr[35]+=1; 

		else if(TRUE) 
			fr[36]+=1;
	}

	for(i=0; i<size; i++)
{
		printf("%2d",fr[i]);
}
}	
