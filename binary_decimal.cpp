#include <iostream>
#include <math.h>

using namespace std;

void bintodec()
{
    int sum = 0;
    string num;

    cin >> num;
    
    for(int i = num.length(); i>=0; i--)
    {
        if(num[i] == '1')
        {
            sum += pow(2, i);
            cout << i << endl;
        }
    }
    cout << sum << endl;
}

void dectobin()
{
    
}

int main()
{
    bool running = true;
    int choice;

    while(running)
    {
        cout << "1: binary to decimal | 2: decimal to binary | 3: end" << endl;

        cin >> choice;

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