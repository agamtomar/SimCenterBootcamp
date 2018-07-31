# include <stdio.h>
# include <stdlib.h>

int mySum(int *data, int size);

int main(int argc, char **argv)
{
	int size = argc - 1;
	int len = 0;
	
	int *data = (int *)malloc(size*sizeof(int));
	
	for (int len = 0; len < size; len++)
	{
		data[len] = atoi(argv[len+1]);
	}
	
	int sum = mySum(data, size);
	
	printf("%d\n", sum);
}

int mySum(int *data, int size) 
{
	int sum = 0;
		
	for (int i = 0; i < size; i++) {
		sum += *data++;
	}
	return sum;
}