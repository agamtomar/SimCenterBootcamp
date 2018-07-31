# include <stdio.h>

float product_num(float a, float b);

float main()
{
	float fp1, fp2, prod;
	
	printf("Enter first number: ");
	scanf("%f", &fp1);
	
	printf("Enter second number: ");
	scanf("%f", &fp2);
	
	prod = product_num(fp1, fp2);
	
	printf("The product of numbers %f + %f is %f", fp1, fp2, prod);
	
	return (0);
}


float product_num(float a, float b)
{
	return (a*b);
}