/*todo:
    -board
    -
*/

#include <iostream>

using namespace std;

char arr[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
bool valid[9] = {0,0,0,0,0,0,0,0,0};

//bool checkWin();
void playerMove();
//void computerMove();
void printField();

int main()
{
    for(int i = 0; i<9; i++)
    {
        printField();
        playerMove();
    }
}

void playerMove()
{
    int ans;
    do
    {
        cout << "Du bist am zug. (1-9) \n";
        cin >> ans;
    }
    while(valid[ans] || ans > 9 || ans < 1);
    valid[ans] = 1;

    if(ans == 1)
    {
        arr[0][0] = 'o';
    }
    else if(ans == 2)
    {
        arr[0][1] = 'o';
    }
    else if(ans == 3)
    {
        arr[0][2] = 'o';
    }
    else if(ans == 4)
    {
        arr[1][0] = 'o';
    }
    else if(ans == 5)
    {
        arr[1][1] = 'o';
    }
    else if(ans == 6)
    {
        arr[1][2] = 'o';
    }
    else if(ans == 7)
    {
        arr[2][0] = 'o';
    }
    else if(ans == 8)
    {
        arr[2][1] = 'o';
    }
    else if(ans == 9)
    {
        arr[2][2] = 'o';
    }


}

void printField()
{
    cout << arr[0][0] << "|" << arr[0][1] << "|" << arr[0][2] << endl;
    cout << arr[1][0] << "|" << arr[1][1] << "|" << arr[1][2] << endl;
    cout << arr[2][0] << "|" << arr[2][1] << "|" << arr[2][2] << endl;
}


