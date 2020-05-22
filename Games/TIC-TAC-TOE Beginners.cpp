#include<bits/stdc++.h>
using namespace std;

char game[100];
char player_1 = 'X',player_2 = 'O';

void ResetBoard()
{
    for(int i=0;i<9;i++)
    {
        game[i] = i+49;
    }
}

void Draw_the_board()
{
    cout << "--------------\n";
    for(int i=0;i<7;i=i+3)
    {
        cout << game[i] << " | " << game[i+1] << " | " << game[i+2] << " | " << endl;
        cout << "--------------\n";
    }
}

bool Move_valid(int move)
{
    if(game[move]==player_1||game[move]==player_2)
    {
        return false;
    }
    return true;
}

int Get_move()
{
    int c=0,move;
    while(c==0)
    {
        cout << "Enter next move ";
        cin >> move;
        if(move>0&&move<10)
        {
            move--;
            if(Move_valid(move)==true)
            {
                c++;
            }
            else
            {
                cout << "Invalid move,try again";
            }
        }
        else
        {
            cout << "Please enter a number between 1 and 9, invalid move";
        }
        cin.clear();
    }
    return move;
}

void Player_Move(char player,int move)
{
    game[move] = player;
}
bool check_game_full()
{
    int c=0;
    for(int i=0;i<9;i++)
    {
        if(Move_valid(i)==true)
        {
            c++;
        }
    }
    if(c==0)
    {
       return true;
    }
    else
    {
        return false;
    }
}

bool check_player_own(char player)
{
    for(int i = 0; i < 3; i++)
    {
        if (game[i] == player && game[i+3]==player && game[i+6]==player)
            {
                return true;
            }
   }
    for (int i = 0; i < 3; i=i+3)
        {
            if (game[i] == player && game[i+1]==player && game[i+2]==player)
                {
                    return true;
                }
        }
  if(game[0]==player && game[4]==player && game[8]==player)
    {
        return true;
    }
  if(game[2]==player && game[4]==player && game[6]==player)
    {
        return true;
    }
    return false;
}

int check_game_over(char player)
{
    if(check_game_full())
    {
        return -1;
    }
    if(check_player_own(player))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void New_Game(string playerName1,string playerName2)
{
    char player_n;
    string player_n_name;
    int move;
    ResetBoard();
    player_n = player_2;
    while (check_game_over(player_n) ==0)
        {
            if (player_n==player_2)
                {
                    player_n =player_1;
                    player_n_name = playerName1;
                }
            else
                {
                    player_n=player_2;
                    player_n_name= playerName2;
                }
            cout << "It's " << player_n_name << "'s turn. Remember, they play as "<< player_n <<".\n";
            Draw_the_board();
            move = Get_move();
            Player_Move(player_n,move);
        }
    if (check_game_over(player_n) == -1)
        {
            Draw_the_board();
            cout << "Draw!\n";
        }
    if (check_game_over(player_n) == 1)
        {
            Draw_the_board();
            cout << player_n_name << " wins!\n";
        }
}

bool Play_Again()
{
    string input;
    char answer;
    while (true)
    {
        cout<<"Do you want to play again? (y/n)\n";
        getline(cin, input);
        if (input.length()== 1 )
        {
            answer = input[0];
            answer = toupper(answer);
            if (answer=='Y')
        {
            return true;
        }
        if (answer =='N')
            {
                break;
            }
        }
        cout << "Sorry, invalid input" ;
    }
    return false;
}

int main()
{
    string playerName1,playerName2;
    cout << "Input the name of the player - 1: ";
    getline(cin,playerName1);
    cout << "Input the name of the player - 2: ";
    getline(cin,playerName2);
    do
    {
        New_Game(playerName1,playerName2);
    }while(Play_Again());
    return EXIT_SUCCESS;
}
