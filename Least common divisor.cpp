#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

int main(){
	int x,y,a;
	cout << "Input x: "; cin >> x;
	cout << "Input y: "; cin >> y;
	if (x > y){
		a = y;}
	if (y < x){
		a = x;}
	for (int i = 2; i <= a; i++){
		if ((x%i == 0) && (y&i == 0)){
			a = i;
			break;}
	}
	cout << "Least common divisor: " << a;
	getch();
	return 0;
}

