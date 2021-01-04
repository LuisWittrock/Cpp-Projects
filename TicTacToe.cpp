/*
!!!ALGORITHMUS:

A player can play a perfect game of Tic-tac-toe (to win or, at least, draw) if they choose the first available move from the following list, each turn, as used in Newell and Simon's 1972 tic-tac-toe program.[6]

    Win: If you have two in a row, play the third to get three in a row.

    Block: If the opponent has two in a row, play the third to block them.

    Fork: Create an opportunity where you can win in two ways.

    Block Opponent's Fork:

    Option 1: Create two in a row to force the opponent into defending, as long as it doesn't result in them creating a fork or winning. For example, if "X" has a corner, "O" has the center, and "X" has the opposite corner as well, "O" must not play a corner in order to win. (Playing a corner in this scenario creates a fork for "X" to win.)

    Option 2: If there is a configuration where the opponent can fork, block that fork.

    Center: Play the center.

    Opposite Corner: If the opponent is in the corner, play the opposite corner.

    Empty Corner: Play an empty corner.

    Empty Side: Play an empty side.

*/

#include <iostream>

using namespace std;

char arr[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};


bool checkWin();
int countWins(char pc);
bool findWin();
bool preventWin();
void playerMove();
void computerMove();
void printField();
bool checkDraw();

int main()
{
    int moves = 0;
    cout << 1 << "|" << 2 << "|" << 3 << endl;
    cout << "-----" << endl;
    cout << 4 << "|" << 5 << "|" << 6 << endl;
    cout << "-----" << endl;
    cout << 7 << "|" << 8 << "|" << 9 << endl << endl << endl;
    printField();
    for(int i = 0; i<9; i++)
    {
        playerMove();
        moves++;
        printField();
        if(checkWin())
        {
            cout << "*** You win! *** \n";
            break;
        }
        if(moves == 9)
        {
            cout << "*** Draw ***";
            break;
        }
        cout << "opponent is thinking JK he doesnt even have to think against you lol \n";
        computerMove();
        moves++;
        printField();
        if(checkWin())
        {
            cout << "*** You lose! *** \n";
            break;
        }
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
    while(arr[ans-1] == 'x' || arr[ans-1] == 'o' || ans > 9 || ans < 1);

    arr[ans-1] = 'o';
}

void printField()
{
    cout << arr[0] << "|" << arr[1] << "|" << arr[2] << endl;
    cout << "-----" << endl;
    cout << arr[3] << "|" << arr[4] << "|" << arr[5] << endl;
    cout << "-----" << endl;
    cout << arr[6] << "|" << arr[7] << "|" << arr[8] << endl;
}

bool checkWin()
{
    if((arr[0] == arr[1] && arr[1] == arr[2] && arr[0] != ' ') || (arr[3] == arr[4] && arr[4] == arr[5] && arr[3] != ' ') || (arr[6] == arr[7] && arr[7] == arr[8] && arr[6] != ' ') ||
     (arr[0] == arr[3] && arr[3] == arr[6] && arr[0] != ' ') || (arr[1] == arr[4] && arr[4] == arr[7] && arr[1] != ' ') || (arr[2] == arr[5] && arr[5] == arr[8] && arr[2] != ' ') ||
      (arr[2] == arr[4] && arr[4] == arr[6] && arr[2] != ' ') || (arr[0] == arr[4] && arr[4] == arr[8] && arr[0] != ' '))
    {
        return true;
    }
    return false;
}

int countWins(char pc)
{
    int total = 0;

    for(int i = 0; i<9; i++)
    {
        if(arr[i] == ' ')
        {
            arr[i] = pc;
            if(checkWin())
            {
                total++;
            }
            arr[i] = ' ';
        }
    }
    return total;
}

bool findWin()
{
    for(int i = 0; i<9; i++)
    {
        if(arr[i] == ' ')
        {
            arr[i] = 'x';
            if(checkWin())
            {
                return true;
            }
            else
            {
                arr[i] = ' ';
            }
        }
    }
    return false;
}

bool preventWin()
{
    for(int i = 0; i<9; i++)
    {
        if(arr[i] == ' ')
        {
            arr[i] = 'o';
            if(checkWin())
            {
                arr[i] = 'x';
                return true;
            }
            else
            {
                arr[i] = ' ';
            }
        }
    }
    return false;
}

void computerMove()
{
    int win;

    //check for winning postion:
    if(findWin())
    {
        return;
    }

    //prevent enemy from wining:
    if(preventWin())
    {
        return;
    }

    //create fork:
    for(int i = 0; i<9; i++)
    {
        if(arr[i] == ' ')
        {
            arr[i] = 'x';
            if(countWins('x') == 2)
            {
                return;
            }
            else
            {
                arr[i] = ' ';
            }
        }
    }

    //block enemy fork:
    for(int i = 0; i<9; i++)
    {
        if(arr[i] == ' ')
        {
            arr[i] = 'o';
            if(countWins('o') == 2)
            {
                arr[i] = 'x';
                return;
            }
            else
            {
                arr[i] = ' ';
            }
        }
    }

    //make move that will win next round:
    for(int i = 0; i<9; i++)
    {
        if(arr[i] == 'x')
        {
            for(int j = 0; j<9; j++)
            {
                if(arr[j] == ' ')
                {
                    arr[j] = 'x';
                    for(int k = 0; k<9; k++)
                    {
                        if(arr[k] == ' ')
                        {
                            arr[k] = 'x';
                            if(checkWin())
                            {
                                arr[k] = ' ';
                                arr[j] = ' ';
                                return;
                            }
                            arr[k] = ' ';
                            
                        }
                    }
                    arr[j] = ' ';
                }
            }
        }
    }

    //get the middle
    if(arr[4] == ' ')
    {
        arr[4] = 'x';
        return;
    }

    //get a corner (0,2,6,8)
    for(int i = 0; i<9; i+=2)
    {
        if(arr[0] == ' ')
        {
            arr[0] = 'x';
            return;
        }
    }

    //get a side (1,3,5,7)
    for(int i = 1; i<8; i+=2)
    {
        if(arr[i] == ' ')
        {
            arr[i] = 'x';
            return;
        }
    }
}

