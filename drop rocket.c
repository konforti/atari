
/***
*int drop_rocket
*
*Purpose:
*			move the rocket y down, x by tank position.
*Entry:
*
*       
*Exit:
*			TIE   = continue.
*			LOOSE = end of game
*
**********************************************************/

#include "atari.h"




int drop_rocket (
				BOMB	*rocket,
				int		*tank_x,
				int		*tanks,
				short	screen[][ROW],
				char	*tank_shape,
				short	BackGround[][ROW + 1],
				short   Tools_Color[]
				)
{
	int		dir  = 0;
	int		next = 0;
	char    rocket_shape[] = {(char)219, 31};

	if (*tank_x < rocket -> x)
	{
		dir = rocket -> x - 1;
	}

	else if (*tank_x > rocket -> x)
	{
		dir = rocket -> x + 1;
	}

	else
	{
		dir = rocket -> x;
	}
	
	next = screen[dir][(rocket -> y) + 1];

	if (next == TANK_ON)
	{
		Clear_Object (
			screen,
			BackGround,
			rocket -> x,
			rocket -> y - 1,
			0, 2
			);

		rocket -> on = false;	
			
		//CHANGE THE COLOR OF THE TANK WHAN GOT SHOT.
		Move_Object (
			BackGround, 
			tank_shape,
			LIGHT_RED,
			*tank_x - 2,
			ROW,
			5, 0
			);
			
		-- *tanks;
			
		SetColor(YELLOW, LIGHT_BLUE);
		SetCursor (70, 0);
		printf("TANKS:%d",*tanks);
		sndPlaySound ("Explode.wav", SND_SYNC);
	
		// GIVE THE TANK THE ORIGINAL COLOR.
		Move_Object (
			BackGround, 
			tank_shape,
			Tools_Color[TAN],
			*tank_x - 2,
			ROW,
			5, 0
			);
	}	
	
	else if (rocket -> y >= ROW - 1)
	{
		Clear_Object (
			screen,
			BackGround,
			rocket -> x,
			rocket -> y - 1,
			0, 2
			);
	
		rocket -> on = false;
	}
		
	else //((next == 0 || next == ARROW_ON) && rocket -> y < ROW)
	{
		Clear_Object (
			screen,
			BackGround,
			rocket -> x,
			rocket -> y - 1,
			0, 3
			);
		
		rocket -> x = dir;
		rocket -> y ++;
			
		Move_Object (
			BackGround,
			rocket_shape,
			Tools_Color[BOM],
			rocket -> x,
			rocket -> y - 1,
				0, 2);
	}		

	
	if (*tanks > 0) return TIE;
	else            return LOOSE;
}