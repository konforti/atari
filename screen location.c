
/***
*void screen_location 
*
*Purpose:
*			 put tools int's in screen arrey.	
*		 
*			
*Entry:
*			
*       
*Exit:
*			
*			
***************************************************/

#include "atari.h"



void screen_location (
					  short screen[][ROW],
					  int	x,
					  int	y,
					  int	tool
					  )
{

	if (tool == ARROW_ON)
	{
		screen[x][y] = tool;
		screen[x][y + 1] = 0;
	}
	
	else if (tool == BOMB_ON)
	{
		screen[x][y] = tool;
		screen[x][y - 1] = 0;
	}
	
	else if (tool == TANK_ON)
	{ 
		screen[x - 2][y] = 0;
		screen[x - 1][y] = tool;
		screen[x    ][y] = tool;
		screen[x + 1][y] = tool;
        screen[x + 2][y] = 0;
	}
	
	else if (tool >= 100 && tool < MONSTER_SIZE +100)
	{
		screen[x - 2][y] = 0;
		screen[x - 1][y] = tool;
		screen[x    ][y] = tool;
		screen[x + 1][y] = tool;
        screen[x + 2][y] = 0;
	}
}
		
		
	
