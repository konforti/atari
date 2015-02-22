
/***
*void Clear_Object
*
*Purpose:
*			put zero in screen arrey and space on screen.
*
*Entry:
*
*			short	screen[][ROW]          = hold the real position on screen.
*			short	BackGround[][ROW + 1]  = hold the back ground colors numbers.
*			int		X                      = the X of the starting point.
*			int		Y					   = the Y of the starting point.
*			int		Wide				   = number of char horizontal.
*			int		High				   = number of char vertical.
*       
*Exit:
*
*******************************************************************************/


#include "atari.h"



void Clear_Object (
				   short	screen[][ROW],
				   short	BackGround[][ROW + 1],
				   int		X,
				   int		Y,
				   int		Wide,
				   int		High
				   )
	{
	int j;	
		
	SetCursor (X, Y);
	//clear verticals shapes.
	for (j = 0; j < Wide; j++)
	{
		screen[X + j][Y] = 0; 

		SetColor(
			BLACK,
			BackGround[X + j] [Y]
			);	
		putch (SPACE);
	}
	
	//clear horizental shapes.
	for (j = 0; j < High; j++)
	{
		SetCursor (X, Y + j);
		screen[X][Y + j] = 0; 

		SetColor(
			BLACK,
			BackGround[X] [Y + j]
			);	
		putch (SPACE); 
	}
}