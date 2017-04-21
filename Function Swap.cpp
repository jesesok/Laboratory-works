#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void swapPointer(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swaplink(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    srand((unsigned int) time(NULL));

    const short int range_min = -10;
    const short int range_max = 10;

    int first_numberLink, second_numberLink;
    int first_numberPointer, second_numberPointer;
    first_numberLink = rand() % (range_max - range_min + 1) + range_min;
    second_numberLink = rand() % (range_max - range_min + 1) + range_min;
    first_numberPointer = rand() % (range_max - range_min + 1) + range_min;
    second_numberPointer = rand() % (range_max - range_min + 1) + range_min;

	cout << "Swap Pointer" << endl << endl;
    cout << first_numberPointer << "\t" << second_numberPointer << endl << endl;
    swapPointer(first_numberPointer,  second_numberPointer);
    cout << first_numberPointer << "\t" << second_numberPointer << endl << endl << endl;

	cout << "Swap Link" << endl << endl;
    cout << first_numberLink << "\t" << second_numberLink << endl << endl;
    swaplink (&first_numberLink, &second_numberLink);
    cout << first_numberLink << "\t" << second_numberLink;

    getch();
    return 0;
}
