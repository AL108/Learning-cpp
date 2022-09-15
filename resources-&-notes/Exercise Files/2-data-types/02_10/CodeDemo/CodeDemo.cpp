// Learning C++ 
// Challenge 02_10
// Calculate an Average, by Eduardo Corpeño 

#include <iostream>

using namespace std;

int main(){
	int nums[5] = {1,23,32,24,337};
	float result; 
    // Write your code here
	for (int i = 0; i < sizeof(nums)/sizeof(int); i++) result += (float)nums[i];
	printf("The average is %.2f\n", result/((float)sizeof(nums)/sizeof(int)));
	return (0);
}
