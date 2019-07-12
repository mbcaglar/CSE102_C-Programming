/***********************************************************/
/*                M.BEDİRHAN ÇAĞLAR                        */
/*                                                         */
/*                  22.04.2016                             */
/*                                                         */
/* Bu program bir air hockey oyunu olup parametreler alarak*/
/*gol olup olmadığını kontrol eder.                        */
/*                                                         */
/***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int reflection(int angle);/*ilk açıya -5 +5 aralığında random açı ekleyerek 
return eder */
int kickDisc(double wallWidth, double wallHeight, double ballCenterX, double
kickAngle, double ballRadius, double goalWidth);/*gol olup olmadığını recursion 
sonunda return eder.*/

int main()
{

	printf("\n%d\n",kickDisc(10,26,2,45,1,2));
}

int kickDisc(double wallWidth, double wallHeight, double ballCenterX, double
kickAngle, double ballRadius, double goalWidth)
{
	double yukseklik=0;
	if(goalWidth>wallWidth || ballRadius>wallWidth/2.0 || (ballCenterX<ballRadius || 
ballCenterX>wallWidth-ballRadius))/*fail durumların kontrolü */
		return 0;
	if((ballCenterX==ballRadius && kickAngle>90) || (ballCenterX==wallWidth-
ballRadius && kickAngle<90))/* topun sağ ve sol köşeler için uygun açıyla atma 
koşulu)*/
		return 0; 
	if(wallWidth==goalWidth)/*duvar ile kale eşitse mutlak gol olur */
		return 1;  
/* Açılara göre durumları kontrol eder */
	if(kickAngle==90){
		if(ballCenterX>=(wallWidth-goalWidth)/2.0	&& 
ballCenterX<=(wallWidth+goalWidth)/2.0)
			return 1;
		else return 0;
	}
	else if(kickAngle>90)
	{
		if(kickAngle>175)
			kickAngle=175;
		kickAngle=180-kickAngle;
		yukseklik = tan((kickAngle*3.14)/180)*(ballCenterX-ballRadius);
	}
	else if(kickAngle<90)
	{
		if(kickAngle<5)
			kickAngle=5;
		yukseklik = tan((kickAngle*3.14)/180)*(wallWidth-ballCenterX-ballRadius);	
		
	}
	printf("yy %f\n",yukseklik);	
	wallHeight = wallHeight-yukseklik;/* yuksekliği toplamdan çıkararak son
gittiği x i y ekseninden hesaplar */
	printf("son h %f\n",wallHeight);
	if(wallHeight<=0)
	{	
		ballCenterX = tan(((90-kickAngle)*3.14)/180)*(wallHeight+yukseklik-
ballRadius);
		printf("son x %f",ballCenterX);		
		if(ballCenterX+ballRadius>= (wallWidth-goalWidth)/2.0	&& 
ballCenterX+ballRadius<=(wallWidth+goalWidth)/2.0)
			return 1;
		else return 0;	
	}
	
	
	return kickDisc(wallWidth,wallHeight,ballRadius,reflection(kickAngle),ballRadius,
goalWidth);

}

int reflection(int angle)
{
    srand(angle); 
    angle+=-4+rand()%4;
	return angle;
}
