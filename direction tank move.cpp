
/***
*void direction
*
*Purpose:
*			move the tank left or right.
*Entry:
*
*       
*Exit:
*
*********************************************/

#include "atari.h"

void direction (
				char	key,
				int		*tank_x,
				char    *tank_shape,
				short	screen[][ROW],
				short	BackGround[][ROW + 1],
				short   Tools_Color[]
				)
{

	switch (key)
	{
		case RIGHT : if (*tank_x < 76)
						{
							++ *tank_x;
							
							screen_location (
								screen,
								*tank_x,
								ROW,
								TANK_ON
								);
							
							Move_Object (
								BackGround,
								tank_shape,
								Tools_Color[TAN],
								*tank_x - 2,
								ROW,
								5, 0
								);	
							 																								
						}break;
				
		case LEFT:	if (*tank_x > 2)
						{
							-- *tank_x;
							
							screen_location (
								screen,
								*tank_x,
								ROW,
								TANK_ON
								);
							
							Move_Object (
								BackGround,
								tank_shape,
								Tools_Color[TAN],
								*tank_x - 2,
								ROW,
								5, 0
								);	
						}break;
	}	
}
	
