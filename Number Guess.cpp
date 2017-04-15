#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
int main()
{
	srand (time(NULL)); 
	int secretNumber = rand() % 100 + 1;
	int tries = 0;
	int guess;
	cout << "\n\tWelcome to Game!\n\n";
do
	{
		cout << "Enter a guess: ";
		cin >> guess;
		++tries;
		if (guess > secretNumber)
		{
			cout << "Too high!\n\n";
		}
		else if (guess < secretNumber)
		{
			cout << "Too low!\n\n";
		}
		else
		{
			cout << "\nThat's it! You got it in " << tries << " guess!\n";
		}
	} while (guess != secretNumber);
	getch();
	return 0;
}
