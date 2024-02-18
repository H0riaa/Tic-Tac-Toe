#include <iostream>
#include <windows.h>

using namespace std;

int check();
void board();
void color(unsigned int);


char s[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};   

int check()
{
    if(s[1] == s[2] && s[2] == s[3])
    {
        return 1;
    }
    else if(s[4] == s[5] && s[5] == s[6])
    {
        return 1;
    }
    else if(s[7] == s[8] && s[8] == s[9])
    {
        return 1;
    }
    else if(s[1] == s[4] && s[4] == s[7])
    {
        return 1;
    }
    else if(s[2] == s[5] && s[5] == s[8])
    {
        return 1;
    }
    else if(s[3] == s[6] && s[6] == s[9])
    {
        return 1;
    }
    else if(s[1] == s[5] && s[5] == s[9])
    {
        return 1;
    }
    else if(s[3] == s[5] && s[5] == s[7])
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void board()
{
    system("cls");
    cout << "Player 1(X)  -  Player 2(O)" << "\n\n\n";

    cout << "     |     |     " << '\n';
    cout <<"  "<< s[1] << "  |  " << s[2] << "  |  " << s[3] << '\n';

    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';

    cout << "  " << s[4] <<"  |  " << s[5] << "  |  " << s[6] << '\n';

    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';

    cout << "  " << s[7] << "  |  "<< s[8] << "  |  " << s[9] << '\n';

}

void color(unsigned int id)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), id);
}


int main()
{
 int player = 1;
    int i, choice;
    int mark;
    do
    {
        board();
        
        cout << "Player " << player << "'s move: \n";
        cin >> choice;

        if(player == 1)
        {
            mark = 'X';
        }
        else
        {
            mark = '0';
        }

        if (choice >= 1 && choice <= 9 && s[choice] == '0' + choice)
        {
            s[choice] = mark;
        }
        else
        {
            cout << "INVALID MOVE!!!!\n";
            
        }

        i = check();
        

       if(player == 1)
       {
        player = 2;
       }
       else
       {
        player = 1;
       }

    } while (i == 0);

    board();
    if (i == 1)
    {
        if(player == 1)
        {
            cout << "PLAYER 2 WINS\n";
        }
        else
        {
            cout << "PLAYER 1 WINS\n";
        }
    }
    else
    {
        cout << "DRAW\n";
    }


}