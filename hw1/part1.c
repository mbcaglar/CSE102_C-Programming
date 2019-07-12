/* PART1 */
#include <stdio.h>
int
main()
{
	int midweight1,midweight2,midweight3;
	int homeweight1,homeweight2,finalweight;	
	double midterm1,midterm2,midterm3;		
	double homework1,homework2,final;
	double finalgrade;
	
	printf("Please enter the 1.midterm weight:");
	scanf("%d",&midweight1);

	printf("Please enter the 2.midterm weight:");
	scanf("%d",&midweight2);
	
	printf("Please enter the 3.midterm weight:");
	scanf("%d",&midweight3);
	
	printf("Please enter the 1.homework weight:");
	scanf("%d",&homeweight1);

	printf("Please enter the 2.homework weight:");
	scanf("%d",&homeweight2);
	
	printf("Please enter the final exam weight:");
	scanf("%d",&finalweight);
	
	printf("Please enter the 1.midterm grade:");
	scanf("%lf",&midterm1);
	
	printf("Please enter the 2.midterm grade:");
	scanf("%lf",&midterm2);

	printf("Please enter the 3.midterm grade:");
	scanf("%lf",&midterm3);
		
	printf("Please enter the 1.homework grade:");
	scanf("%lf",&homework1);

	printf("Please enter the 2.homework grade:");
	scanf("%lf",&homework2);

	printf("Please enter the final exam grade:");
	scanf("%lf",&final);
	/* Notların yüzdelerini 100'e bölüp yüzdesiyle çarparak her birini topladım */
	finalgrade = (midterm1/100*midweight1)+(midterm2/100*midweight2)+(midterm3/100*midweight3)+(homework1/100*homeweight1)+(homework2/100*homeweight2)+(final/100*finalweight);
	printf("Your final grade is:%.2f\n",finalgrade); 
}
