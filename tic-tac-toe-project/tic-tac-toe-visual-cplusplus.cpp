/* 
 * Tic Tac Toe game
 * Based on exercise from http://www.cppforschool.com/project/tic-tac-toe-project.html
 * Added CPU player, clear screen for linux terminal and clear board function.
 * author: Karol Tabaka
 * email: din_alt@poczta.onet.pl
 * GNU GPL v.2 2017
 * 
 */
#include <iostream>
#include <unistd.h>
#include <term.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int checkwin();
void board();
void ClearScreen();
int CPU_player();
void game( bool CPU_player_on );
void clear_board( char board[] );

int main()
{
	bool is_cpu_player_on = false;
	bool continue_game = true;
	char number_of_players = ' ';
	srand (time(NULL));
	board();
	while(continue_game == true)
	{
		cout << "How many players will play? (1, 2 or q to quit)" << endl;
		cin >> number_of_players;
		clear_board( square );
		switch(number_of_players)
		{
		case '1':
			is_cpu_player_on = true;
			game(is_cpu_player_on);
			break;
		case '2':
			is_cpu_player_on = false;
			game(is_cpu_player_on);
			break;
		case 'q':
			continue_game = false;
			break;
		default:
			cout << "Wrong choise, try again!" << endl;
		}
		
	}
		
	return 0;
}
/*********************************************
	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}


/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void board()
{
	ClearScreen();
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
	cout << "     |     |     " << endl << endl;
}
/******************clear_board**************************************/
void clear_board( char board[])
{
	string clear_up_board = "0123456789";
	for( int i; i<10; i++)
	{
	board[i] = clear_up_board[i];
	}
}
		
/*******************************************************************
				CLEAR SCREEN FUNCTION
********************************************************************/
void ClearScreen()
  {
  if (!cur_term)
    {
    int result;
    setupterm( NULL, STDOUT_FILENO, &result );
    if (result <= 0) return;
    }

  putp( tigetstr( "clear" ) );
  }
/********************CPU_player**************************************/
int CPU_player()
{
	int cpu_player = 0;
	if ( square[3] == '3' && (square[1] == square[2] || square[7] == square[5] || square[6] == square[9]))
		return 3;
	else if ( square[2] == '2' && (square[1] == square[3] || square[5] == square[8] ))
		return 2;
	else if ( square[1] == '1' && (square[2] == square[3] || square[5] == square[9] || square[4] == square[7] ))
		return 1;
	else if ( square[4] == '4' && (square[1] == square[7] || square[5] == square[6] ))
		return 4;
	else if ( square[5] == '5' && (square[4] == square[6] || square[1] == square[9] || square[2] == square[8] || square[3] == square[7] ))
		return 5;
	else if ( square[6] == '6' && (square[4] == square[5] || square[3] == square[9] ))
		return 6;
	else if ( square[7] == '7' && (square[1] == square[4] || square[3] == square[5] || square[8] == square[9] ))
		return 7;
	else if ( square[8] == '8' && (square[2] == square[5] || square[7] == square[9] ))
		return 8;
	else if ( square[9] == '9' && (square[1] == square[5] || square[7] == square[8] || square[3] == square[6] ))
		return 9;
	else
		return cpu_player = rand()%9 + 1;
}
/*********************game*******************************************/
void game( bool CPU_player_on )
{
	int player = 1,i,choice;
	char mark;
	do
	{
		board();
		player=(player%2)?1:2;
		cout << "Player " << player << ", enter a number (0 for exit):  ";
		if( player == 2 && CPU_player_on == true )
		{
			choice = CPU_player();
			cout << choice;
		}
		else
		cin >> choice;
		mark=(player == 1) ? 'X' : 'O';
		if( choice == 0 )
			break;
		else if (choice == 1 && square[1] == '1')
			square[1] = mark;
		else if (choice == 2 && square[2] == '2')
			square[2] = mark;
		else if (choice == 3 && square[3] == '3')
			square[3] = mark;
		else if (choice == 4 && square[4] == '4')
			square[4] = mark;
		else if (choice == 5 && square[5] == '5')
			square[5] = mark;
		else if (choice == 6 && square[6] == '6')
			square[6] = mark;
		else if (choice == 7 && square[7] == '7')
			square[7] = mark;
		else if (choice == 8 && square[8] == '8')
			square[8] = mark;
		else if (choice == 9 && square[9] == '9')
			square[9] = mark;
		else
		{
			cout<<"Invalid move ";
			player--;
			cin.ignore();
			cin.get();
		}
		i=checkwin();
		player++;
	}while(i==-1);
	board();
	if(i==1)
		cout<<"==>\aPlayer "<<--player<<" win ";
	else
		cout<<"==>\aGame draw";
	cin.ignore();
	cin.get();
}
