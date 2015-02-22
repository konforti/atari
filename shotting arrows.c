
/***
*void shoting 
*
*Purpose:
*			 chack for the next position (on screen arrey) of the arrow.	
*			 act by result.
*			
*Entry:
*			
*       
*Exit:
*			
*			
***************************************************************************/


#include "atari.h"



void shoting (
			  ARROW		arrow_arrey[],
			  short		screen[][ROW],
			  MONSTER	*monster_arrey,
			  BOMB		*skad,
			  int		*counter,
			  int		*monster_faster,
			  short		BackGround[][ROW + 1],
			  MONSTER	*bonus,
			  int		*tanks,
			  short		Tools_Color[]
			  )
			 
{
	int j, next;
	char  arrow_shape[2] =  {ARROW_SIGN, SPACE};
	
		for (j = 0; j < ARROW_SIZE; j++)
		{
			// chack the arrows in the air.
			if (arrow_arrey [j].on)
			{
				// chack first the the old place for horizontal tools.					
				next = screen[arrow_arrey [j].x][arrow_arrey [j].y];

			    //if the names of the monsters.
				if (next >= 100 && next < MONSTER_SIZE + 100)  
				{
					hit_monster (
						screen,
						monster_arrey,
						(next - 100),						
						&arrow_arrey[j],
						monster_faster,
						counter,
						BackGround
						);
				}
				//if bonus monster.
				else if (next == BONUS_ON)
				{
					Hit_Bonus (
						screen,
						BackGround,
						&arrow_arrey[j],
						bonus,
						tanks
						);
				}
				
			}
			// if its still on air.
			if (arrow_arrey [j].on)
			{
				// than chack the new place for all tools.
				next = screen[arrow_arrey [j].x][arrow_arrey [j].y - 1];
				
				// if the way is clear
				if (next == 0 && arrow_arrey [j].y > 1)
				{
				    arrow_arrey[j].y --;		
					
					screen_location(
						screen,
						arrow_arrey[j].x,
						arrow_arrey[j].y,
						ARROW_ON
						);						 
					
					Move_Object (
						BackGround,
						arrow_shape,
						Tools_Color[ARR],
						arrow_arrey[j].x,
						arrow_arrey[j].y,
						0, 2
						);
				}
				
				//if the names of the monsters.
				else if (next >= 100 && next <= MONSTER_SIZE + 100)  
				{
					hit_monster (
						screen,
						monster_arrey,
						(next - 100),						
						&arrow_arrey[j],
						monster_faster,
						counter,
						BackGround
						);
				}

				//if a bomb ahead of you. 
				else if (next == BOMB_ON)
				{
					hit_bomb (
						screen,
						&arrow_arrey[j],
						skad,
						BackGround
						);
				}
				
				//if a bonus monster ahead of you.
				else if (next == BONUS_ON)
				{
					Hit_Bonus (
						screen,
						BackGround,
						&arrow_arrey[j],
						bonus,
						tanks
						);
				}

				//if the ground ahead of you. 
				else if (arrow_arrey [j].y <= 1)
				{
					arrow_arrey [j].on = false;
					screen[arrow_arrey [j].x][arrow_arrey [j].y] = 0;
					
					SetColor(Tools_Color[ARR],
						BackGround[arrow_arrey[j].x][arrow_arrey[j].y]);
					
					SetCursor (arrow_arrey [j].x,
						arrow_arrey [j].y );
					
					putch(SPACE);
				}
			}
		}
}


