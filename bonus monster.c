/***
*void bonus_monster
*
*Purpose:
*			move the bonus monster on screen.
*
*Entry:
*       
*Exit:
*
************************************************/

#include "atari.h"


void bonus_monster (
					MONSTER *bonus,
					short	BackGround[][ROW + 1],
					short	screen[][ROW],
					short   Tools_Color[]
					)
{
		static bool flag = true;
		char		bonus_horizontal_shape[3] = {16, 4, 17};
		char		bonus_vertical_shape[3]   = {31, 4, 30};
        
		
		
		if (flag)
		{
			//clear vertical shape.
			Clear_Object (
				screen,
				BackGround,
				bonus -> x,
				bonus -> y - 1,
				0, 3
				);			
		
			bonus -> x -- ;

			//print horizontal shape.
			screen[bonus -> x][bonus -> y] = BONUS_ON;
			Move_Object (
				BackGround,
				bonus_horizontal_shape,
				Tools_Color[BON],
				bonus -> x - 1,
				bonus -> y,
				3, 0
				);
			
			flag = false;
		}
		
		else if (!flag)//horizontal
		{
			//clear horizontal shape.
			Clear_Object (screen,
				BackGround,
				bonus -> x - 1,
				bonus -> y,
				3, 0);
			
		
			bonus -> x --;

			//print vertical shape.
			screen[bonus -> x][bonus -> y] = BONUS_ON;
			Move_Object (
				BackGround,
				bonus_vertical_shape,
				Tools_Color[BON],
				bonus -> x,
				bonus -> y - 1,
				0, 3
				);
					
			flag = true;
		}
		// clear & turn off in end of screen.
		if (bonus -> x < 2)
		{		
			Clear_Object (
				screen,
				BackGround,
				bonus -> x - 1,
				bonus -> y,
				3, 0
				);
			
			Clear_Object (
				screen,
				BackGround,
				bonus -> x ,
				bonus -> y- 1,
				0, 3
				);
			
			bonus -> on = false;
			flag		= true;
			bonus -> x  = COL - 10;//STARTING POINT.

		}
}