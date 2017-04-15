#include <iostream>
using namespace std;

bool power2(int number);
int degree2 (int n);

int main(){
    int x;
    char again;
    do
    {
        cout << "Input number: ";
        cin >> x;
        cout << endl << power2(x) << endl << endl;
        cout << degree2(x) << endl << endl;
        cout << "Do you want to play again? "; cin >> again; cout << endl;
    } while (again != 'n');
    cout << "Good bye!";
    return 0;
}

int degree2 (int n){
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return degree2(n/2);
    }
    return 0;
}

bool power2 (int number){
    if(number <= 0)
        return false;
    while((number % 2)==0)
    {
        if((number/=2) == 1)
            return true;
    }
    return false;
}
