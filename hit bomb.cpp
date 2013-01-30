/***
*void hit_bomb
*
*Purpose:
*			clear bomb and arrow if hit.
*			
*Entry:
*		
*       
*Exit:
*
*			
***********************************************/


#include "atari.h"



void hit_bomb (
			   short	screen[][ROW],
			   ARROW	*Killing_Arrow,
			   BOMB		*Dead_Skad,
			   short	BackGround[][ROW + 1]
			   )
{
	//clear arrow.
	Clear_Object(
		screen,
		BackGround,
		Killing_Arrow -> x,
		Killing_Arrow -> y,
		1, 0
		);
	
	Killing_Arrow -> on = false;
	Killing_Arrow -> y = -1;		
	
	//clear bomb.
	Clear_Object(
		screen,
		BackGround,
		Dead_Skad -> x,
		Dead_Skad -> y,
		1, 0
		);
	
	Dead_Skad -> on = false;
}