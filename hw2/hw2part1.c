/* PART1 */
#include <stdio.h>
void calculateLastGrade();
int main()
{
	calculateLastGrade();
	calculateLastGrade();
	calculateLastGrade();
	
}
void calculateLastGrade()
{
	int midWeight1,homeWeight1,finalWeight;
	double midTerm1,homework1,final;
	double finalGrade;
	
	printf("Please enter the 1. midterm weight: ");
	scanf("%d",&midWeight1);

	printf("Please enter the 1. homework weight: ");
	scanf("%d",&homeWeight1);
	
	printf("Please enter the final exam weight: ");
	scanf("%d",&finalWeight);
	
	printf("Please enter the 1. midterm grade: ");
	scanf("%lf",&midTerm1);
		
	printf("Please enter the 1. homework grade: ");
	scanf("%lf",&homework1);

	printf("Please enter the final exam grade: ");
	scanf("%lf",&final);
	/* Notları 100'e bölüp yüzdesiyle çarparak her birini toplayarak final grade
	notunu hesapladım. */
	
	finalGrade = (midTerm1/100*midWeight1)+(homework1/100*homeWeight1)+
				 (final/100*finalWeight);
	
	printf("Your final grade is: %.2f\n",finalGrade); 
}
