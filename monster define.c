
/***
*void monster_define
*
*Purpose:
*			define monster shape by level,
*			put monster arrey in starting posisition.
*			
*Entry:
*		
*       
*Exit:
*
*			
**********************************************************/

#include "atari.h"


void monster_define (
					 MONSTER	*monster_arrey,
					 char		*monster_shape,
					 short		screen[][ROW],
					 short		BackGround[][ROW + 1],
					 short		Tools_Color[],
					 int        level
					 )
{
	int i, j;

	if (level == 1)
	{
		monster_shape[0] = SPACE;
		monster_shape[1] = (char)247;
		monster_shape[2] = 4;
		monster_shape[3] = (char)247;
		monster_shape[4] = SPACE;
		monster_shape[5] = '\0';
	}
	
	else if (level == 2)
	{
		monster_shape[0] = SPACE;
		monster_shape[1] = 17;
		monster_shape[2] = 4;
		monster_shape[3] = 16;
		monster_shape[4] = SPACE;
		monster_shape[5] = '\0';	
	}
	
	else if (level == 3)
	{
		monster_shape[0] = SPACE;
		monster_shape[1] = 16;
		monster_shape[2] = 4;
		monster_shape[3] = 17;
		monster_shape[4] = SPACE;
		monster_shape[5] = '\0';

	}
	
	
			
    for (i = 0; i < MONSTER_SIZE; i++)
	{		
		monster_arrey [i].on   = true; 
		monster_arrey [i].x    = ((i % (MONSTER_SIZE/3)) * 5 + 3);
	    monster_arrey [i].y    = ((i / (MONSTER_SIZE/3)) + 1);
		
		screen_location (
			screen,
			(monster_arrey [i].x),
			(monster_arrey [i].y),
			i + 100
			);
		
		SetCursor(
			monster_arrey [i].x - 2,
			monster_arrey [i].y
			);
		
		for (j = 0; j < 5; j++)
		{
			SetColor(
				Tools_Color[MON],
				BackGround[monster_arrey [i].x - 2 + j][monster_arrey [i].y]
				);
			
			putch (monster_shape[j]);
		}		 
    }
}

