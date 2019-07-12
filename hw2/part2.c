#include <stdio.h>
#include <math.h>
#define PI 3
int areaofRectangle(int width, int height);
int perimeterofRectangle(int width, int height);
int areaOfCircle(int radius);
int perimeterOfCircle(int radius);
int areaOfSquare(int kenar);
int perimeterOfSquare(int kenar);
int main()
{
	int width,height;
	int radius,kenar;

	printf("Please enter the width of rectangle:");
	scanf("%d",&width);	

	printf("Please enter the height of rectangle:");
	scanf("%d",&height);

	printf("The area of the rectangle is: %d\n",areaofRectangle(width,height));
	printf("The perimeter of the rectangle is: %d\n",
	perimeterofRectangle(width,height));

	printf("Please enter the width of square:");
	scanf("%d",&kenar);
	
	printf("The area of the square is: %d\n",areaOfSquare(kenar));
	printf("The perimeter of the square is: %d\n",perimeterOfSquare(kenar));

	printf("Please enter the radius of circle:");
	scanf("%d",&radius);
	
	printf("The area of the circle is: %d\n",areaOfCircle(radius));
	printf("The perimeter of the circle is: %d\n",perimeterOfCircle(radius));
}
int areaofRectangle(int width, int height)
{
	return width*height;
}
int perimeterofRectangle(int width, int height)
{
	int perimeter;
	perimeter = 2*(width+height);	
	return perimeter;
}

int areaOfCircle(int radius)
{
	int area;	
	area = PI*pow(radius,2);
	return area;
}
int perimeterOfCircle(int radius)
{
	
	return 2*PI*radius;
}
int areaOfSquare(int kenar)
{
	return pow(kenar,2);
}
int perimeterOfSquare(int kenar)
{
	return 4*kenar;
}
