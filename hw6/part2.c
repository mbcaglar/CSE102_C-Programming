#include <stdio.h>
#include <string.h>
char *matcher(char *hatstack,char *needle);
int main()
{
	char *ptr=matcher("aaasi","asi");
	printf("%s",ptr);
}
char *matcher(char *hatstack,char *needle)
{
	int i,j,n,len;
	int a,k,count;
	n = strlen(hatstack);
	printf("%d",n);
	len = strlen(needle);
	printf("\n%d\n",len);	
	count = 0;
	k = 0;
	j = 0;	
	a = len;
	if(hatstack==NULL || needle==NULL || n<len )
	    return 0;	
	for(i=0; i<n; i++)
	{

		while(hatstack[i]!=' ')
		{
				len = a;
				k=i;
				while(len>=j)
				{
					if(len%2!=0 && hatstack[i]==needle[j])
					{
						count ++;
						if(j==0)						
							k=i;
						if(len%2!=0 && count==len/2+1)
							return hatstack+k;					
						j+=2;
						i+=2;
										}				
					else if(len%2==0 && hatstack[i]==needle[j])
					{
						count ++;
						if(j==0)
							k=i;
						if(count==len/2)
							return hatstack+k;
						j+=2;
						i+=2;

					}
					else
					{
						len=-1;
						count=0;
						j=0;
						i=k;	
					}
				}

		i++;
		}	
}

	return 0;
}
