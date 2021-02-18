#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

void bintodec()
{
    cout << "binary to decimal \n binary number: ";
    int sum = 0;
    string num;
    cout << endl; 
    cin >> num;

    for(int i = 0, j = num.length()-1; i < num.length(); i++, j--)
    {
        if(num[i] == '1')
        {
            sum += pow(2, j);
        }
    }
    cout << sum << endl;
}

void dectobin()
{
    cout << "decimal to binary \n decimal number: ";
    int num;
    cin >> num;
    string sum;
    cout << endl;			
    while(num != 0)
    {
        sum.insert(0,(to_string(num % 2)));
        num /= 2;
        
    }
    cout << sum << endl;
}

int main()
{
    bool running = true;
    int choice;

    while(running)
    {
        cout << "1: binary to decimal | 2: decimal to binary | 3: end" << endl;
	cout << "function: ";
        cin >> choice;
	cout << endl;

        switch (choice)
        {
        case 1:
            bintodec();
            break;
        case 2:
            dectobin();
            break;
        case 3:
            running = false;
            break;
        
        default:
            break;
        }
    }

}
