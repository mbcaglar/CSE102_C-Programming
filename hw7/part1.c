/***********************************************************/
/*                M.BEDİRHAN ÇAĞLAR                        */
/*                                                         */
/*                  14.04.2016                             */
/*                                                         */
/* Bu programda girilen arrayin palindrome olup olmadığını */
/*sadece harfleri önemseyerek kontrol eder.                */
/*                                                         */
/***********************************************************/
#include <stdio.h>

int isPalindrome(char *str);

void son_arr(char *str,int *size);/* arrayi sadece harlere çevirir */

int yardimci(char *str,int sol_index,int sag_index);/*recursion yaparak sag ve 
sol indexteki karakterleri kontrol eder */



int main()

{
	char str[] = {"A z  B *CDedcba"};

	isPalindrome(str);
	printf("%d\n",isPalindrome(str));
	return 0;

}

int isPalindrome(char *str)
{

	int i,n;
	int sag_index;
	int sol_index;

    i=0;
	n=0;	

	while(str[i]!='\0')/* stringin eleman sayısını buluyoruz */

	{

		i++;
		n++;

	}

	son_arr(str,&n);
	sag_index = n-1;
	sol_index = 0;

	return yardimci(str,sol_index,sag_index);/*düzden ve tersten aynı olup 
olmamasını index parametreleri ile kontrol eder */

}

int yardimci(char *str, int sol_index, int sag_index)

{  

	if(str == NULL || sol_index < 0 || sag_index < 0)
	{
		return 0;
	}
	if(sag_index<=sol_index)
		return 1;/*recursion sonunda indexler eşitlenir yada sag index daha 
kücük olursa return 1 döner */
	if(str[sol_index] == str[sag_index])/*indexleri artırıp azaltarak recursion 
yapar */

	{	
		return yardimci(str,sol_index+1,sag_index-1);
	}

     return 0;

}

void son_arr(char *str,int *size)

{

	int i,j;	

	j=0;

	for(i=0; i<*size; i++)

	{

		if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122))

		{			
			if(str[i]>=65 && str[i]<=90)
				str[i]+=32;	

			str[j]=str[i];

			j++;


		}

	}

	*size=j;
	str[j]='\0';

}
