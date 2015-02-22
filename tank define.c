
/***
*void tank_define 
*
*Purpose:
*			define the shape and put it in starting position.	
*			 
*			
*Entry:
*			
*       
*Exit:
*			
*			
****************************************************************/

#include "atari.h"


void tank_define (
				  short screen[][ROW],
				  char	*tank_shape,
				  int	tank_x,
				  short	BackGround[80][ROW + 1],
				  short Tools_Color[]
				  )
{
	int j;

	tank_shape[0] = (SPACE);
	tank_shape[1] = (17);
	tank_shape[2] = (char)(254);
	tank_shape[3] = (16);
	tank_shape[4] = (SPACE);
	tank_shape[5] = '\0';

	screen_location(screen,
		tank_x,
		ROW,
		TANK_ON);
	
	SetCursor (tank_x - 2, ROW);
	
	for(j = 0;j < 5; j++)
	{
		SetColor(Tools_Color[TAN],
			BackGround[tank_x - 2 + j][ROW]);	
		
		putch (tank_shape[j]);
	}
}