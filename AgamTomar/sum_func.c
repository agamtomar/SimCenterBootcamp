# include <stdio.h>

int sumInt(int a, int b);

int main()
{
	int int1, int2, sum;
	
	printf("Enter first integer: ");
	scanf("%d", &int1);
	
	printf("Enter second integer: ");
	scanf("%d", &int2);
	
	sum = sumInt(int1, int2);
	
	printf("The sum of integers %d + %d is %d", int1, int2, sum);
	
	return (0);
}


int sumInt(int a, int b)
{
	return (a+b);
}