#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int func_choice(int x);

int bisection(int x1, int x2);

int main()
{
    cout << "Your number is " << bisection(0,1000);
    getch();
    return 0;
}

int func_choice(int x) {
    int tries;
    back: ++tries;
    cout << "\nYour number is " << x << endl;
    cout << "+ - It is more" << endl;
    cout << "- - It is less" << endl;
    cout << "= - It is equally" << endl << endl;
    cout << "Choice (+/-/=)? ";
    char choice; cin >> choice;
    switch(choice)
    {
        case '+': return +1;
        case '-': return -1;
        case '=': cout << "\nThat's it! Computer got it in " << tries << " guess!\n"; return 0;
        default: cout << "\nChoose correct answer" << endl << endl;
            goto back;
    }
}

int bisection(int x1, int x2) {
    int x = (x1 + x2) / 2;
    int y = func_choice(x);
    while (abs(y) > 0.001)
    {
        if (y > 0)
            x1 = x;
        else
            x2 = x;

        x = (x1 + x2) / 2;
        y = func_choice(x);
    }
    return x;
}
