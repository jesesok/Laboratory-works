#include <iostream>
#include <cstring>
using namespace std;

	int main() {
	const short int SIZE = 100;
	char sentence[SIZE];
	cout << "Input sentence: "; gets(sentence);
	int templine; // variable to exchange line items
     for (int i = 0; i < strlen(sentence) - 1; i++) {
        for (int j = 0; j < strlen(sentence) - i - 1; j++) {
            if (sentence[j] > sentence[j + 1]) {
                // change items in places
                templine = sentence[j];
                sentence[j] = sentence[j + 1];
                sentence[j + 1] = templine;
            }
        }
    }
    // output sorted array to the console
    cout << "\nNew sentence: " << endl;
    for (int i = 0; i < strlen(sentence); i++) 
	{
        cout << sentence[i] << " ";
    }
	return 0; 
	}
