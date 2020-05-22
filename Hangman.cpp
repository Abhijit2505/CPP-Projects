#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

int TRY=3;
string message = "PLAY";
int cheking (char guess, string secretmonth, string &guessmonth)
{
	int i;
	int matches=0;
	int len=secretmonth.length();
	for (i = 0; i< len; i++)
	{

		if (guess == guessmonth[i])
			return 0;

		if (guess == secretmonth[i])
		{
			guessmonth[i] = guess;
			matches++;
		}
	}
	return matches;
}
void screen_graphics()
{
	 system("color 02");
    system("cls");

    cout << "\n\t\tYOU HAVE " << TRY << " TRIES TO TRY AND GUESS THE MONTH ";
    cout<<"\n\n\t\t\t\t"+message;
}

int main()
{
	string name;
	char letter;
	string month;
    string months[] ={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULE",
                      "AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
	srand(time(NULL));
	int n=rand()% 12;
	month=months[n];
	string hide_m(month.length(),'X');
	while (TRY!=0)
	{
		screen_graphics();
		cout << "\n\n\t\t\t\t" << hide_m;
		cout << "\n\n\t\t\t\tGUESS A LETTER: ";
		cin >> letter;

		if (cheking(letter, month, hide_m)==0)
		{
			message = "INCORRECT LETTER";
			TRY = TRY - 1;
		}
		else
		{
			message = "NICE! YOU GUESSED A CORRECT LETTER ";
		}
		if (month==hide_m)
		{
			message = "CONGRATULATIONS ! YOU GOT IT ";
			screen_graphics();
			cout << "\n\t\t\t\tTHE MONTH IS : " << month << endl;
			break;
		}
	}
	if(TRY == 0)
	{
		message = "DANGER !!! YOU HAVE BEEN HANGED";
		screen_graphics();
		cout << "\n\t\t\t\t THE MONTH WAS : " << month << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}
