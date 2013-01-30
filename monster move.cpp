
/***
*int monster_move 
*
*Purpose:
*			move all monsters that still alive left or right by flag.	
*			and down by monsterdown timer.
*			
*Entry:
*		
*       
*Exit:
*			TIE   = continue.
*			LOOSE = end of game.
*			
*********************************************************************/

#include "atari.h"


int monster_move (
				  MONSTER	*monster_arrey,
				  char		*monster_shape,
				  short		screen[][ROW],
				  int		*newline,
				  short		BackGround[][ROW + 1],
				  short		Tools_Color[]
				  )
{
	int              i;
	int              win_loose    = WIN; 

	static bool      flag         = false;// move left or right.
	static clock_t   monsterdown  = 0;
	

	if (monsterdown < clock())
	{
		TIMER(monsterdown, MONSTER_DOWN);
		 		
		for (i = 1; i < COL - 1; i++)
		{
			screen[i][*newline] = 0; //clear the upper line of monsters.
			
			SetCursor(i, *newline);
			
			SetColor(
				Tools_Color[MON],
				BackGround[i][*newline]
				);
			
			putch (SPACE);
		}
		 ++ *newline ; //sign the new start line of the monsters. 		
	}
				  

	
	

	if (!flag)//monsters go right.
	{
			for (i = MONSTER_SIZE - 1; i >= 0; i--)
		{
			if (monster_arrey [i].on)
			{
				win_loose = TIE;	
				
				monster_arrey [i].x ++;
				monster_arrey [i].y = (i / (MONSTER_SIZE/3)) + *newline; 
				
				screen_location (
					screen,
					monster_arrey [i].x, monster_arrey [i].y,
					i + 100
					);
				
			
				Move_Object (
					BackGround, 
					monster_shape,
					Tools_Color[MON],
					monster_arrey[i].x - 2,
					monster_arrey[i].y,
					5, 0
					);
						
				if ((monster_arrey [i].x + 3) == COL )
					flag = true;

				if (monster_arrey [i].y  == ROW - 1)
				{
					win_loose = LOOSE;
					break;
				}
				
			}
		}

	}
	else//monsters go left.
	{
		for (i = 0; i < MONSTER_SIZE; i++)
		{
			if (monster_arrey [i].on)
			{
	            win_loose = TIE;
			
				monster_arrey [i].x --;				
				monster_arrey [i].y = (i / (MONSTER_SIZE/3)) + *newline;
				
				screen_location (
					screen,
					monster_arrey [i].x,
					monster_arrey [i].y,
					i + 100
					);
				
				
				Move_Object (
					BackGround, 
					monster_shape,
					Tools_Color[MON],
					monster_arrey[i].x - 2,
					monster_arrey[i].y,
					5, 0
					);
				

				if ((monster_arrey [i].x - 2) == 0)
					flag = false;

				if (monster_arrey [i].y  == ROW)
				{
					win_loose = LOOSE;
					break;
				}
			}
		}
	}
	if (win_loose != TIE) 
		*newline = 1;

	return win_loose;
}


