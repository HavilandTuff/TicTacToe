#include <ncurses.h>
#include <stdlib.h>
#include <string>
using namespace std;
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int checkwin();
void board();
void clear_board( char board[]);
int CPU_player();
int main()
{
	srand (time(NULL));
    initscr(); 
    board();
    
    getch();
    endwin();
    return 0;
}

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

void board()
{
	clear();
	int columns = 0;
	int rows = 0;
	char title[] = "Tic Tac Toe";
	char info_line[] = "Player 1 (X)  -  Player 2 (O)";
	char empty_line[] = "     |     |     ";
	char data_line[] = "     |     |     ";
	char bottom_line[] = "_____|_____|_____";
	
	
	getmaxyx( stdscr, rows, columns ); 
    mvprintw( rows / 2 -6,( columns / 2 ) -( sizeof( title ) / 2 ), title );
    mvprintw( rows / 2 -5, ( columns / 2) - (sizeof( info_line ) / 2 ), info_line ); 
    mvprintw( rows / 2 -3, ( columns / 2) - (sizeof( data_line ) / 2 ), data_line );
    data_line[2] = square[1];
    data_line[8] = square[2];
    data_line[14] = square[3]; 
    mvprintw( rows / 2 -2, ( columns / 2) - (sizeof( data_line ) / 2 ), data_line );
    mvprintw( rows / 2 -1, ( columns / 2) - (sizeof( bottom_line ) / 2 ), bottom_line );
    mvprintw( rows / 2 , ( columns / 2) - (sizeof( empty_line ) / 2 ), empty_line );
    data_line[2] = square[4];
    data_line[8] = square[5];
    data_line[14] = square[6];
    mvprintw( rows / 2 +1, ( columns / 2) - (sizeof( data_line ) / 2 ), data_line );
    mvprintw( rows / 2 +2, ( columns / 2) - (sizeof( bottom_line ) / 2 ), bottom_line );
    mvprintw( rows / 2 +3, ( columns / 2) - (sizeof( empty_line ) / 2 ), empty_line );
    data_line[2] = square[7];
    data_line[8] = square[8];
    data_line[14] = square[9];
    mvprintw( rows / 2 +4, ( columns / 2) - (sizeof( data_line ) / 2 ), data_line );
    mvprintw( rows / 2 +5, ( columns / 2) - (sizeof( empty_line ) / 2 ), empty_line );
    
}

void clear_board( char board[])
{
	string clear_up_board = "0123456789";
	for( int i; i<10; i++)
	{
	board[i] = clear_up_board[i];
	}
}

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
