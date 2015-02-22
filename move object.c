/***
*void Move_Object 
*
*Purpose:
*			print a string on the back ground,	
*			taking the back griund color from the back ground arrey.
*			
*Entry:
*			short	BackGround[][ROW + 1]  = hold the back ground colors numbers.
*			char    *Shape                 = get string with the shpe to print.			  
*			int     Color                  = get int for color of the shape. 
*           int		X                      = the X of the starting point.
*			int		Y					   = the Y of the starting point.
*			int		Wide				   = number of char horizontal.
*			int		High				   = number of char vertical.
*       
*Exit:
*			
*			
*******************************************************************************/


#include "atari.h"



void Move_Object (
				  short BackGround[][ROW + 1],
				  char  *Shape,				  
				  int   Color,
				  int   X,
				  int   Y,
				  int   Wide,
				  int   High
				  )
{
	int j;	
		
		SetCursor (X, Y);
	//move horizontal object.
	for (j = 0; j < Wide; j++)
	{
		SetColor(
			Color,
			BackGround[X + j] [Y]
			);	
		
		putch (Shape[j]);
	}
	//move vertical object.
	for (j = 0; j < High; j++)
	{
		SetCursor (X, Y + j);
		SetColor(
			Color,
			BackGround[X] [Y + j]
			);	
		
		putch (Shape[j]); 
	}
}