/* PART2 */

/*M.Bedirhan ÇAĞLAR 22/02/2016 */

/*Bu program sizden aldığı tarih bilgileriyle sizin kaç gündür yaşadığınızı
hesaplamaktadır.Ayrıca eğer farklı bir gezegende yaşasaydınız kaç yaşınızda 
olcaktınız çıktısınıda vermektedir.*/

#include <stdio.h>
int
main()
{
	int year,month,day;
	int birthYear,birthMonth,birthDay;
	int currentDate,birthDate,totalDays;
	int days,months,hours,planeTotaldays;
	int planetYear,planetMonth,planetDay;

	printf("Please enter the current date.\n");
	
	printf("Year : ");
	scanf("%d",&year);
	
	printf("Month : ");
	scanf("%d",&month);

	printf("Day : ");
	scanf("%d",&day);
	
	printf("Please enter your birthdate.\n");
	
	printf("Year : ");
	scanf("%d",&birthYear);
	
	printf("Month : ");
	scanf("%d",&birthMonth);

	printf("Day : ");
	scanf("%d",&birthDay);
	/* Bu günün tarihini ve doğum günü tarihinin hepsini gün biçiminde yazıyoruz
    */
	currentDate =(year*365)+(month*30)+day;
	birthDate =(birthYear*365)+(birthMonth*30)+birthDay;	
	totalDays = currentDate-birthDate;
	
	printf("You have lived %d days.\n",totalDays);

	printf("Please enter about the time of another planet\n");
	
	printf("How many hours in a day? ");
	scanf("%d",&hours);
	
	printf("How many days in a month? ");
	scanf("%d",&days);
	
	printf("How many months in a year? ");
	scanf("%d",&months);
	/*Dünyadaki yaşadığımız günü 24 ile çarparak saate çevirip bir gezegendeki 
	1 gün saatine bölerek o gezegendeki toplam günü elde ederiz.*/
	planeTotaldays = (double)(totalDays*24)/hours;
	planetYear = planeTotaldays/(months*days); /*totali bir yıldaki gün sayısına
  	integer bölerek yılı elde ederiz.*/
	
	planetMonth = (planeTotaldays%(months*day))/days; /*totalin bir yıldaki gün 
	sayısına göre modunun güne integer bölümü bize ayı verir.*/
	
	planetDay = (planeTotaldays%(months*day))%days; /*totalin bir yıldaki gün 
	sayısına göre modunun güne göre modu da bize günü verir. */
	
	printf("If you lived in a planet where a day is %d hours,a month is %d days and a year is %d months : you were %d years,%d months and %d days old.\n",hours,days,months,planetYear,planetMonth,planetDay);


}
