#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <fstream>

void create_origin_array(const int range_max, const int range_min, int numberOfElements, int *originArray);

void create_binary_array(const int elements, const int *originArray, int *binaryArray);

void math_work(int numberOfElements, const int *originArray, int &indexOfLNN, int &indexOfPN);

using namespace std;

int main() {

    srand((unsigned) time(NULL));
    const int elements = 1000;
    const int range_max = 28;
    const int range_min = -28;
    int numberOfElements = 0;
    char nameOfOriginFile[elements] = "numbers.bin";
    char nameOfFinalFile[elements] = "final_numbers.bin";
    char nameOfBinaryFile[elements] = "binary_numbers.bin";
    int originArray[elements] = {0};
    int binaryArray[elements] = {0};

    cout << "Input number of element: ";
    cin >> numberOfElements;
    numberOfElements = abs(numberOfElements);

    create_origin_array(range_max, range_min, numberOfElements, originArray);

    ofstream foutOrigin(nameOfOriginFile, ios_base::binary);
    if (foutOrigin.is_open()) {
        foutOrigin.write((char *) originArray, sizeof(originArray));
        foutOrigin.close();
    }

    int indexOfLNN;
    int indexOfPN;
    math_work(numberOfElements, originArray, indexOfLNN, indexOfPN);

    if (indexOfPN != -1 && indexOfLNN != -1) {
        int temp = originArray[indexOfLNN];
        originArray[indexOfLNN] = originArray[indexOfPN];
        originArray[indexOfPN] = temp;
    } else {
        getch();
        return 0;
    }

    ofstream foutFinal(nameOfFinalFile, ios_base::binary);
    if (foutFinal.is_open()) {
        foutFinal.write((char *) originArray, sizeof(originArray));
        cout << "Final array: " << endl;
        for (int i = 0; i < numberOfElements; i++) {
            cout << i << ") " << originArray[i] << endl;
        }
        foutFinal.close();
    }

    create_binary_array(elements, originArray, binaryArray);

    ofstream foutBinary(nameOfBinaryFile, ios_base::binary);
    if (foutBinary.is_open()) {
        foutBinary.write((char *) binaryArray, sizeof(binaryArray));
        cout << "\nBinary array: " << endl;
        for (int i = 0; i < numberOfElements; i++) {
            cout << i << ") " << binaryArray[i] << endl;
        }
        foutBinary.close();
    }

    getch();
    return 0;
}

void math_work(int numberOfElements, const int *originArray, int &indexOfLNN, int &indexOfPN) {
    indexOfLNN = -1;
    indexOfPN = -1;
    int lastNegativeNumber = 1;
    for (int i = numberOfElements - 1; i > 0; i--) {
        if (originArray[i] < 0) {
            lastNegativeNumber = originArray[i];
            indexOfLNN = i;
            break;
        }
    }

    if (lastNegativeNumber == 1) {
        cout << "\nWe have not negative numbers" << endl;
    } else {
        cout << "\nIt is the last negative number: " << originArray[indexOfLNN] << endl;
        cout << "Its index: " << indexOfLNN << endl;
    }

    int perfectNumber = 1;
    for (int j = 0; j < numberOfElements; j++) {
        if (originArray[j] == 6 || originArray[j] == 28) {
            perfectNumber = originArray[j];
            indexOfPN = j;
            break;
        }
    }

    if (perfectNumber == 1) {
        cout << "We have not perfect numbers" << endl;
    } else {
        cout << "It is the first perfect number: " << perfectNumber << endl;
        cout << "Its index: " << indexOfPN << endl
             << endl;
    }
}

void create_binary_array(const int elements, const int *originArray, int *binaryArray) {
    for (int i = 0; i < elements; i++) {
        binaryArray[i] = originArray[i] >> 2;                                                // i/2^2
        binaryArray[i] = (binaryArray[i] ^ (binaryArray[i] >> 31)) - (binaryArray[i] >> 31); // module
        binaryArray[i] =
                (binaryArray[i] ^ -1) + 1;                                          // reversal of the sign of number
    }
}

void create_origin_array(const int range_max, const int range_min, int numberOfElements, int *originArray) {
    cout << "\nOrigin array: " << endl;
    for (int i = 0; i < numberOfElements; i++) {
        originArray[i] = rand() % (range_max - range_min + 1) + range_min;
        cout << i << ") " << originArray[i] << endl;
    }
}