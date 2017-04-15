#include <iostream>
#include <conio.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>

void sort_index(char *stroka);

void bubble(char *stroka, int templine);

using namespace std;

int main()
{
    const short int TSIZE = 1000;
    char stroka[TSIZE];
    
	int indet;
    char *sentence = new char[indet];
    
	const short int ABC = 27;
    char alphabet[ABC];
	
	int choice;
    char again;
    char letter; // readable character
    int index = 0; // counter
    int templine = 0; // variable to exchange line items
	
    for (letter = 'a'; letter <= 'z'; letter++)
    {
        alphabet[index]= letter;
        index++;
    }
    alphabet[index] = '\0';
    cout << alphabet;
    do
    {
        system("cls");
        cout << "Input static sentence: "; gets(stroka);
        cin.get();
        cout << "\nNumber of elements in the dynamic line: "; cin >> indet; indet = abs(indet);
        cin.get();
        cout << "\nInput dynamic sentence: "; gets(sentence);
		back:
		system("cls");
		cout << "\nYour static sentence: " << stroka << endl;
		cout << "\nYour dynamic sentence: " << sentence << endl;
		cout << "\nWhat do you want?" << endl << endl;
        cout << "1 - Work with index" << endl;
        cout << "2 - Work with pointer" << endl << endl;
        cout << "Your choice is "; cin >> choice; cout << endl;
        switch(choice)
        {
            case 1:
                bubble(stroka, templine);
                cout << stroka;
		        strcat(stroka, alphabet);
                sort_index(stroka);
 			cout << "New stroka: " << stroka << endl;
                break;
            case 2: 
				bubble(sentence, templine);
				strcat(sentence, alphabet);
				sort_index(sentence);		
        cout << "New sentence: " << sentence << endl;
			    break;
            default:
                system("cls");
                cout << "Choose the correct answer" << endl;
                goto back;
        }

        cout << "\nDo you want to work again? (y/n): "; cin >> again;
    } while (again == 'y');
    delete []sentence;
	getch();
    return 0;
}

void bubble(char *stroka, int templine) {
    for (int i = 0; i < strlen(stroka) - 1; i++)
                {
                    for (int j = 0; j < strlen(stroka) - i - 1; j++)
                    {
                        if (stroka[j] > stroka[j + 1])
                        {   // change items in places
                            templine = stroka[j];
                            stroka[j] = stroka[j + 1];
                            stroka[j + 1] = (char) templine;
                        }
                    }
                }
}

void sort_index(char *stroka) {
    for(int j = 0; j < strlen(stroka); j++)
    {
        int count = 0;
        bool check = false;
        if(!isspace(stroka[j]))
        {
            for(int i = j + 1; i < strlen(stroka); i++)
            {
                if(!isspace(stroka[i]))
                {
                    if(stroka[j] == stroka[i])
                    {
                        count = j;
                        check = true;
                        stroka[i] = -1;
                    }
                }
            }
            if(check)
            {
                stroka[count] = -1;
            }
        }
    }
}


