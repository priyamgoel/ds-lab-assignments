// Question 3)Predict the Output of the following program

#include<iostream>
using namespace std;

int main()
 {
int i;
int arr[5] = {1};
for (i = 0; i < 5; i++)
printf("%d",arr[i]);
return 0;
 }
 
 // output will be 10000
 // initializing with braces, makes other values zero instead of garbage,
 // so that is why rest of them print 0.
