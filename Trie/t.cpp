#include<iostream>
#include<cmath>

using namespace std;

int main(){
int x = 23456;
int numIterations = 0;
int xCopy = x;
while(x){
    x /= 10;
    ++numIterations;
}
while(xCopy){
        // long divisor = pow(10,numIterations); 
        // cout << divisor << endl;
        int dubCopy = xCopy;
        cout << xCopy%10 << endl;
        xCopy = dubCopy/10;
}
}
