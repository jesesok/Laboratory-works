#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

/*
int create(const short range_min, const short range_max, const short numbersElements, int *originArray,
           int *finalArray, int *newArray, int count, int temp, int amount, int average);

void WorkWithStream();
*/

using namespace std;

int main() {
    srand((unsigned) time(NULL));
    cout << endl;
    const short int range_min = -10;
    const short int range_max = 10;
    const short int numbersElements = 10;
    int originArray[numbersElements] = {0};
    int finalArray[numbersElements] = {0};
    int newArray[numbersElements] = {0};
    int count = 0;
    int temp = 0;
    int amount = 0;
    int average = 0;

    // Original array

    /*
   temp = create(range_min, range_max, numbersElements, originArray, finalArray, newArray, count, temp, amount,
                  average);
    */

    for (int i = 0; i < numbersElements; i++) {
        originArray[i] = rand() % (range_max - range_min + 1) + range_min;
        amount += originArray[i];
        count++;
    }

    cout << "Amount: " << amount << endl
         << endl;
    average = amount / count;
    cout << "Average: " << average << endl
         << endl;

    for (int j = 0; j < count; j++) {
        if (originArray[j] > average && originArray[j] > 0) {
            finalArray[temp] = originArray[j];
            temp++;
        }
    }

    for (int i = 0; i < numbersElements; i++) {
        newArray[i] = originArray[i] >> 2;                                       // i/2^2
        newArray[i] = (newArray[i] ^ (newArray[i] >> 31)) - (newArray[i] >> 31); // module
        newArray[i] = (newArray[i] ^ -1) + 1;                                    // reversal of the sign of number
    }

    ofstream originOut("origin.bin", ios_base::binary);
    if (originOut.is_open()) {
        originOut.write((char *) originArray, sizeof(originArray));
        originOut.close();
    }

    ofstream originBin("originBinary.bin", ios::binary);
    if (originBin.is_open()) {
        originBin.write((char *) newArray, sizeof(newArray));
        originBin.close();
    }

    ofstream originFin("final.bin", ios::binary);
    if (originFin.is_open()) {
        originFin.write((char *) finalArray, sizeof(finalArray));
        originFin.close();
    }

    ofstream textInBinary;
    textInBinary.open("textow.txt");
    for (int i = 0; i < temp; i++)
        textInBinary << finalArray[i] << endl;
    textInBinary.close();

    /*
    WorkWithStream();
    */

    ifstream finOut("origin.bin", ios_base::binary);
    int powerCount1 = 0;
    cout << "Original Array: " << endl;
    while (finOut.read((char *) &powerCount1, sizeof(int))) {
        cout << powerCount1 << ' ';
    }
    cout << endl
         << endl;
    finOut.close();

    ifstream finBin("originBinary.bin", ios_base::binary);
    int powerCount2 = 0;
    cout << "Binary array: " << endl;
    while (finBin.read((char *) &powerCount2, sizeof(int))) {
        cout << powerCount2 << ' ';
    }
    cout << endl
         << endl;
    finBin.close();

    ifstream finFin("final.bin", ios_base::binary);
    int powerCount3 = 0;
    cout << "Final Array: " << endl;
    while (finFin.read((char *) &powerCount3, sizeof(int))) {
        cout << powerCount3 << ' ';
    }
    cout << endl
         << endl;
    finFin.close();

    getch();
    return 0;
}

/*void WorkWithStream() {
    ifstream finOut("origin.bin", ios_base::binary);
    int powerCount1 = 0;
    cout << "Original Array: " << endl;
    while (finOut.read((char *)&powerCount1, sizeof(int)))
    {
        cout << powerCount1 << ' ';
    }
    cout << endl << endl;
    finOut.close();

    ifstream finBin("originBinary.bin", ios_base::binary);
    int powerCount2 = 0;
    cout << "Binary array: " << endl;
    while (finBin.read((char *)&powerCount2, sizeof(int)))
    {
        cout << powerCount2 << ' ';
    }
    cout << endl << endl;
    finBin.close();

    ifstream finFin("final.bin", ios_base::binary);
    int powerCount3 = 0;
    cout << "Final Array: " << endl;
    while (finFin.read((char *)&powerCount3, sizeof(int)))
    {
        cout << powerCount3 << ' ';
    }
    cout << endl << endl;
    finFin.close();
}
*/

/*int create(const short range_min, const short range_max, const short numbersElements, int *originArray,
           int *finalArray, int *newArray, int count, int temp, int amount, int average) {
    for (int i = 0; i < numbersElements; i++)
    {
        originArray[i] = rand() % (range_max - range_min + 1) + range_min;
        amount += originArray[i];
        count++;
    }

    cout << "Amount: " << amount << endl << endl;
    average = amount / count;
    cout << "Average: " << average << endl << endl;

    for (int j = 0; j < count; j++)
    {
        if (originArray[j] > average && originArray[j] > 0)
        {
            finalArray[temp] = originArray[j];
            temp++;
        }
    }

    for(int i = 0; i < numbersElements; i++)
    {
        newArray[i] = originArray[i] >> 2; // i/2^2
        newArray[i] = (newArray[i] ^ (newArray[i] >> 31)) - (newArray[i] >> 31); // module
        newArray[i] = (newArray[i] ^ -1) + 1; // reversal of the sign of number
    }
    return temp;
}
*/