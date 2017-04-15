// z1 = cos^4(x) + sin^2(y) + 1/4sin^2(2x) - 1
// z2 = sin (x+y) * sin (x-y)
#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

int main()
{
	setlocale (0, "");
	double x, y, z1, z2;
	cout << "X: "; cin >> x;
	cout << "Y: "; cin >> y;
	z1 = pow (cos (x*M_PI/180), 4.0) + pow (sin (y*M_PI/180), 2.0) + 1.0/4.0 * pow (sin (2.0 * x*M_PI/180), 2.0) - 1.0;
	z2 = sin ((x+y)*M_PI/180) * sin ((x-y)*M_PI/180);
	cout << "Z1: " << z1 << endl;
	cout << "Z2: " << z2;
	getch ();
	return 0;
}
