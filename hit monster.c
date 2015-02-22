
/***
*void hit_monster
*
*Purpose:
*			clear monster and arrow if hit.
*			monster move get faster.
*           add 100 point to points.
*			
*Entry:
*		
*       
*Exit:
*
*			
***********************************************/

#include "atari.h"



void hit_monster (
				  short    screen[][ROW],
				  MONSTER  *monster_arrey,
				  int      Dead_Monster, 
				  ARROW    *Killing_Arrow,
				  int      *monster_faster,
				  int      *counter,
				  short    BackGround[][ROW + 1]
				  )
{
	int i;
	
	// in case there was monsters under the monster who 
	// got shot they will destroyd too.
	for (i = Dead_Monster; i < MONSTER_SIZE; i += (MONSTER_SIZE/3))
	{
		if (monster_arrey[i].on)
		{
			Clear_Object (
				screen,
				BackGround,
				monster_arrey[i].x - 1,
				monster_arrey[i].y,
				3, 0
				);
				
		
			monster_arrey[i]. on = false;
			
			//monster move get faster.           
			*monster_faster += 15;
			
			//add 100 point to points.
			*counter += 100;
			
			SetColor(YELLOW, BackGround[0][0]);
			SetCursor (0, 0);
			printf("POINTS:%d",*counter);	
		}
	}
	//clear arrow from screen and put zero in his place. 	
    Clear_Object (
		screen,
		BackGround,
		Killing_Arrow -> x,
		Killing_Arrow -> y,
		1, 0
		);
    
	Killing_Arrow -> on = false;
	Killing_Arrow -> y = -1;
	
	//player get 100 points and the speed get faster.
	
	sndPlaySound ("Gunshot.wav", SND_ASYNC);
}