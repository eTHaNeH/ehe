/*
 * Linux getch()
 */

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
//#include <curses.h>

typedef unsigned int u32;

typedef struct {
	u32 a;
	u32 b;
}Arr;

void printArr(Arr *arr);

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
	//	int a = 0;
#if 0
	//	u32 arr[7] = {7,2,3,5,4,9,1};
	u32 arr[7] = {0,2,3,5,4,9,10};
	u32 tmp;
	int i, idx;

	for(i = 0; i < 7; i++)
	{ 
		printf("%d ", arr[i]);
	}
	printf("\r\n");

	for(i = 1; i < 7; i++)
	{
		idx = i;
		tmp = arr[i];
		while((idx>0) && (arr[idx-1]>tmp)){
			arr[idx] = arr[idx-1];
			idx--;
		}
		arr[idx] = tmp;
	}

	for(i = 0; i < 7; i++)
	{ 
		printf("%d ", arr[i]);
	}
	printf("\r\n");
	//	a = 1;
	//	int b = 3+a;
	//	printf("%d\r\n", b);
#endif
	/*
	   char str[100];

	   sprintf(str, "%d, %s = %d\n", 100, "is one hundred.", 100);

	   printf("%s", str);	
	 */

	//	initscr();
	unsigned int a = 2;
	int b = -2;

	char c;

	//	initscr();

	c = getch();
	//	endwin();
	if(c == '?') printf("help\r\n");

	return 1;
}

