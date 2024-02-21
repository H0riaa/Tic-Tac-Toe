#include <iostream>
#include <windows.h>

using namespace std;

int check();
void board();
void color(unsigned int);
int i;


char s[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};   

int check()
{
    if (s[1] == s[2] && s[2] == s[3])
    {
        return 1;
    }
    else if (s[4] == s[5] && s[5] == s[6])
    {
        return 1;
    }
    else if (s[7] == s[8] && s[8] == s[9])
    {
        return 1;
    }
    else if (s[1] == s[4] && s[4] == s[7])
    {
        return 1;
    }
    else if (s[2] == s[5] && s[5] == s[8])
    {
        return 1;
    }
    else if (s[3] == s[6] && s[6] == s[9])
    {
        return 1;
    }
    else if (s[1] == s[5] && s[5] == s[9])
    {
        return 1;
    }
    else if (s[3] == s[5] && s[5] == s[7])
    {
        return 1;
    }
    else(s[1] != '1' && s[2] != '2' && s[3] != '3' &&
        s[4] != '4' && s[5] != '5' && s[6] != '6' &&
        s[7] != '7' && s[8] != '8' && s[9] != '9' && i == 0 );
    {
        return 2;
    }
    
}



void board()
{
    system("cls");
    cout << "Player 1(X)  -  Player 2(O)" << "\n\n\n";

    cout << "     |     |   " << '\n';
    
    if(s[1] == 'X')
    {
        color(1);
    }
      else if(s[1] == '0')
    {
        color(4);
    }
    cout <<"  " <<s[1];
    color(7);


    cout << "  |  ";
    if(s[2] == 'X')
    {
        color(1);
    }
    else if(s[2] == '0')
    {
        color(4);
    }
    cout << s[2];
    color(7);


    cout << "  |  ";


    if(s[3] == 'X')
    {
        color(1);
    }
    else if(s[3] == '0')
    {
        color(4);
    }
    cout << s[3];
    color(7);
    cout << '\n';


    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  ";


    if(s[4] == 'X')
    {
        color(1);
    }
    else if(s[4] == '0')
    {
        color(4);
    }
    cout << s[4];
    color(7);


    cout << "  |  ";
    if(s[5] == 'X')
    {
        color(1);
    }
    else if(s[5] == '0')
    {
        color(4);
    }
    cout << s[5];
    color(7);


    cout << "  |  ";
    if(s[6] == 'X')
    {
        color(1);
    }
    else if(s[6] == '0')
    {
        color(4);
    }
    cout << s[6];
    color(7);
    cout << '\n';


    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  ";


    if(s[7] == 'X')
    {
        color(1);
    }
    else if(s[7] == '0')
    {
        color(4);
    }
    cout << s[7];
    color(7);
    

    cout << "  |  ";


    if(s[8] == 'X')
    {
        color(1);
    }
    else if(s[8] == '0')
    {
        color(4);
    }
    cout << s[8];
    color(7);


    cout << "  |  ";


    if(s[9] == 'X')
    {
        color(1);
    }
    else if(s[9] == '0')
    {
        color(4);
    }
    cout << s[9];
    color(7);
    cout << '\n';
    
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
    bool draw = false;
    do
    {
        board();

        if(draw)
        {
            cout << "DRAW\n";
            break;
        }
        
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
            i = check();
            if(i == 1)
            {
                draw = false;
            }
            
            if(player == 1)
            {
                player = 2;
            }
            else
            {
                player = 1;
            }        
        }

        else
        {
            cout << "INVALID MOVE!!!!\n";  
        }
        
        
        if(i == 1)
        {
            board();
            if(player == 1)
            {
                cout << "PLAY 2 WINS\n";
            }
            else
            {
                cout << "PLAYER 1 WINS\n";
            }
            break;
        }

        draw = true;
        for(int j = 1; j <= 9; j++)
        {
            if(s[j] == '0' + j)
            {
                draw = false;
                break;
            }
        }
    } 
    while (true);

    return 0;
}