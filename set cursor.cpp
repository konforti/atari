/***
*void SetCursor 
*
*Purpose:
*			 set (x, y) position on screen for printing.	
*		 
*			
*Entry:
*			
*       
*Exit:
*			
*			
*******************************************************************************/


#include "atari.h"


void SetCursor (
				int x,
				int y
				)
{
	HANDLE stdoutput;// handle to console screen buffer
	COORD c;
	CONSOLE_CURSOR_INFO v;// address of cursor information
	
	
	stdoutput=GetStdHandle ( STD_OUTPUT_HANDLE );

	v.dwSize   = 100;
	v.bVisible = true;
	SetConsoleCursorInfo ( stdoutput, &v );
	
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition ( stdoutput, c );
}

            


	
	


 
