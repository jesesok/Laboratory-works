/* First perfect. Last negativ. Swap. New array */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main() {

    const int elements = 80;
    char nameOfOriginFile[elements] = "numbers.txt";
    int numberOfElements = 0;
    char nameOfFinalFile[elements] = "final_numbers.txt";
     
    cout << "Input number of element: ";
    cin >> numberOfElements;

    ofstream fout;
    fout.open(nameOfOriginFile); 
    int randomNumber = 0;
    
    cout << "\nOrigin array: " << endl;
    for (int i = 0; i < numberOfElements; i++){
        randomNumber = 100 - (rand() % 201);
        cout << i << ") " << randomNumber << endl;
        fout << randomNumber << endl;
    }
    
    cout << endl;
    fout.close(); 

    ifstream fin(nameOfOriginFile); 
    int *mass = new int[numberOfElements];
    for (int i = 0; !fin.eof(); i++) {
        fin >> mass[i];
    }
    fin.close();

    int lastNegativeNumber = 1;
    int indexOfLNN = -1;

    for (int i = numberOfElements - 1; i > 0; i--) {
        if (mass[i] < 0) {
            lastNegativeNumber = mass[i];
            indexOfLNN = i;
            break;
        }
    }

    if (lastNegativeNumber == 1) {
        cout << "We have not negative numbers" << endl;
    } else {
        cout << "It is the last negative number: " << mass[indexOfLNN] << endl;
        cout << "Its index: " << indexOfLNN << endl;
    }

    int perfectNumber = 1;
    int indexOfPN = -1;

    for (int j = 0; j < numberOfElements; j++) {
        if (mass[j] == 6 || mass[j] == 28) {
            perfectNumber = mass[j];
            indexOfPN = j;
            break;
        }
    }

    if (perfectNumber == 1) {
        cout << "We have not negative numbers" << endl;
    } else {
        cout << "It is the first perfect number: " << perfectNumber << endl;
        cout << "Its index: " << indexOfPN << endl << endl;
    }

    if (indexOfPN != -1 && indexOfLNN != -1) {
        int temp = mass[indexOfLNN];
        mass[indexOfLNN] = mass[indexOfPN];
        mass[indexOfPN] = temp;
    } else {
        getch();
        return 1;
    }

    ofstream changeFout;
    changeFout.open(nameOfFinalFile);
    cout << "Final array: " << endl;
    for (int i = 0; i < numberOfElements; i++) {
        changeFout << mass[i] << endl;
        cout << i << ") " << mass[i] << endl;
    }
    changeFout.close();
    
    delete[] mass;
    getch();
    return 0;
}
