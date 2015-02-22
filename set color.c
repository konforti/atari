/***
*void SetColor 
*
*Purpose:
*			 set fore ground color and back ground color for printing.	
*		 
*			
*Entry:
*			
*       
*Exit:
*			
*			
************************************************************************/


#include "atari.h"


void SetColor (
			   int forecolor,
			   int backcolor
			   )
{
	HANDLE hConsule;
	WORD   ForeColor;
	WORD   BackColor;
	
	hConsule = GetStdHandle (STD_OUTPUT_HANDLE);

	BackColor = backcolor;
	ForeColor = forecolor;
	
	SetConsoleTextAttribute( hConsule,( WORD ) 
			(  (BackColor << 4) | ForeColor ) );
} 