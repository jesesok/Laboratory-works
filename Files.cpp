#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include <ctime>

char *originTitle(const short TSIZE, char *title1);

void ofStreamOld(int numbersElements, const char *title1);

void addition(int numbersElements, const int *originArray, int average);

void OfStreamNew(const char *title2, const int *finalArray, int temp);

char *finalTitle(const short TSIZE, char *title2);

void streamFinal(const int *fRandarr, int temporary, FILE *file_final, const char *finalName);

void streamOld(const short num, FILE *file_origin, const char *originName);

using namespace std;

int main() {
    int numbersElements;
    cout << "\nNumber of real numbers: ";
    cin >> numbersElements;
    numbersElements = abs(numbersElements);

    int choice;
    back:
    cout << "\nWhat do you want?" << endl
         << endl;
    cout << "1 - Work with <fstream>" << endl;
    cout << "2 - Work with classical C" << endl;
    cout << "\nYou choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            const short int TSIZE = 15;
            char *title1 = new char[TSIZE];
            char *title2 = new char[TSIZE];

            title1 = originTitle(TSIZE, title1);

            ofStreamOld(numbersElements, title1);

            ifstream fin;
            fin.open(title1);
            if (!fin) {
                cout << "Cannot open file " << title1 << " for reading" << endl;
                return 1;
            }
            int k;
            int originArray[numbersElements];
            int count = 0;
            int amount = 0;
            while (fin >> k) {
                originArray[count] = k;
                amount += originArray[count];
                count++;
            }
            cout << "\nAmount: " << amount << endl;
            fin.close();

            int average = amount / count;
            int finalArray[numbersElements];
            int temp = 0;
            for (int j = 0; j < count; j++) {
                if ((originArray[j] > average) && (originArray[j] > 0)) {
                    finalArray[temp] = originArray[j];
                    temp++;
                }
            }

            addition(numbersElements, originArray, average);

            title2 = finalTitle(TSIZE, title2);

            OfStreamNew(title2, finalArray, temp);

            delete[] title1;
            delete[] title2;
            break;
        }

        case 2: {
            const short int num = 15;
            int amounts = 0;
            int counts = 0;
            int oRandarr[num];

            FILE *file_origin;
            char *originName = (char *) "numbers.txt";

            streamOld(num, file_origin, originName);

            file_origin = fopen(originName, "r");
            for (int i = 0; i < num; i++) {
                fscanf(file_origin, "%d", &oRandarr[i]);
            }
            fclose(file_origin);

            cout << "\nOriginal array " << endl;
            for (int i = 0; i < num; i++) {
                cout << oRandarr[i] << endl;
                amounts += oRandarr[i];
                counts++;
            }

            cout << "\nAmount: " << amounts << endl;

            int averages = amounts / counts;
            int fRandarr[num];
            int temporary = 0;
            for (int j = 0; j < counts; j++) {
                if ((oRandarr[j] > averages) && (oRandarr[j] > 0)) {
                    fRandarr[temporary] = oRandarr[j];
                    temporary++;
                }
            }

            cout << "\nAverage: " << averages << endl;

            FILE *file_final;
            char *finalName = (char *) "new_numbers.txt";

            streamFinal(fRandarr, temporary, file_final, finalName);

            break;
        }

        default:
            system("cls");
            cout << "\nInput correct answer" << endl;
            cout << "\nNumber of real numbers: " << numbersElements << endl;
            goto back;
    }

    getch();
    return 0;
}

void streamOld(const short num, FILE *file_origin, const char *originName) {
    file_origin = fopen(originName, "w");
    fclose(file_origin);
    file_origin = fopen(originName, "a");
    srand((unsigned int) time(NULL));
    for (int i = 0; i < num; i++) {
        fprintf(file_origin, "%d ", (rand() % 201) - 100);
    }
    fclose(file_origin);
}

void streamFinal(const int *fRandarr, int temporary, FILE *file_final, const char *finalName) {
    file_final = fopen(finalName, "w");
    for (int i = 0; i < temporary; i++) {
        fprintf(file_final, "%d ", fRandarr[i]);
    }
    fclose(file_final);

    cout << "\nFinal array: " << endl;
    for (int i = 0; i < temporary; i++) {
        cout << fRandarr[i] << endl;
    }
}

char *finalTitle(const short TSIZE, char *title2) {
    cout << "\nInput title for your final file: ";
    cin.getline(title2, TSIZE);
    title2 = strcat(title2, ".txt");
    return title2;
}

void OfStreamNew(const char *title2, const int *finalArray, int temp) {
    ofstream foutes;
    foutes.open(title2);
    cout << "\nFinal array" << endl;
    for (int i = 0; i < temp; i++)
        foutes << finalArray[i] << endl;
    for (int i = 0; i < temp; i++)
        cout << finalArray[i] << endl;
    foutes.close();
}

void addition(int numbersElements, const int *originArray, int average) {
    cout << "\nOriginal array" << endl;
    for (int i = 0; i < numbersElements; i++)
        cout << originArray[i] << endl;
    cout << "\nAverage = " << average << endl;
}

void ofStreamOld(int numbersElements, const char *title1) {
    ofstream fout;
    fout.open(title1);
    srand((unsigned int) time(NULL));
    for (int i = 0; i < numbersElements; i++)
        fout << (rand() % 201) - 100 << endl;
    fout.close();
}

char *originTitle(const short TSIZE, char *title1) {
    cout << "\nInput title for your origin file: ";
    cin.get();
    cin.getline(title1, TSIZE);
    title1 = strcat(title1, ".txt");
    return title1;
}