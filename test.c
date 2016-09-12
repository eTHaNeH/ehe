/*
 * Linux getch()
 */

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
//#include <curses.h>

/* reads from keypress, doesn't echo */
char getch(void)
{
	struct termios oldattr, newattr;
	char ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}

/* reads from keypress, echoes */
int getche(void)
{
	struct termios oldattr, newattr;
	int ch;
	tcgetattr( STDIN_FILENO, &oldattr );
	newattr = oldattr;
	newattr.c_lflag &= ~( ICANON );
	tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	return ch;
}

int main(void)
{
	char c;

	c = getch();
	if(c == '?') printf("help\r\n");

	return 1;
}

