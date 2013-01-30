/***
*int drop_bombs
*
*Purpose:
*			chack the next step to the bomb and act by result.
*
*Entry:
*       
*Exit:
*			TIE   = continue this level. 
*			LOOSE = end of game.
*
****************************************************************/



#include "atari.h"




int drop_bombs (
				BOMB	*skad,
				MONSTER *monster_arrey,
				int		*tank_x,
				int		*tanks,
				short	screen[][ROW],
				char	*tank_shape,
				short	BackGround[][ROW + 1],
				short   Tools_Color[]
				)
{

	int		next = 0;
	char    bomb_shape[3] =  {SPACE, BOMB_SIGN, SPACE};
	
	next = screen[skad -> x][(skad -> y) + 1];

	if (next == TANK_ON)
	{
		Clear_Object (
			screen,
			BackGround,
			skad -> x,
			skad -> y,
			0, 1
			);

		skad -> on = false;	
			
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
			
		SetColor(YELLOW, BackGround[70][0]);
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
	
	else if (skad -> y >= ROW - 1)
	{
		Clear_Object (
			screen,
			BackGround,
			skad -> x,
			skad -> y,
			0, 1
			);
			
		skad -> on = false;
	}
		
	else //((next == 0 || next == ARROW_ON) && skad -> y < ROW)
	{
		skad -> y ++;
			
		screen_location(
			screen,
			skad -> x,
			skad -> y,
			BOMB_ON
			);
			
			
		Move_Object (
			BackGround,
			bomb_shape,
			Tools_Color[BOM],
			skad -> x,
			skad -> y - 1,
			0, 3
			);
	}		

	
	if (*tanks > 0) return TIE;
	else            return LOOSE;
}