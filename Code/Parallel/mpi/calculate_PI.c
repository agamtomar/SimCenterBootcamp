# include <stdio.h>
# include <time.h>

static int long numSteps = 100000;


float Area(float current_x, float step_size){
	float y, area;
	y = 4.0/(1+current_x * current_x);
	area = y * step_size;
	return area;
}


int main(){
	double pi = 0;
	double time = 0;
	float area, x = 0, step_size = 1.0/numSteps, sum = 0;
	for (int i=0; i<numSteps; i++){
		area = Area(x, step_size);
		sum = sum + area;
		x = x + step_size;
	}
	pi = sum;
	printf("PI=%f, duration: %f ms\n", pi, time);
	return 0;
}


