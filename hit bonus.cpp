
/***
*void Hit_Bonus
*
*Purpose:
*			clear bonus and arrow if hit.
*           add one soul to tanks.
*			
*Entry:
*		
*       
*Exit:
*
*			
***********************************************/

#include "atari.h"





void Hit_Bonus (
				short	screen[][ROW],
				short	BackGround[][ROW + 1],
				ARROW	*Killing_Arrow,
				MONSTER *Dead_Bonus,
				int		*tanks
				)
{
	//clear bonus if hrizontal.					
	Clear_Object(
		screen,
		BackGround,
		Dead_Bonus -> x - 1,
		Dead_Bonus -> y,
		3, 0
		);
	
	//clear bonus if vertical.
	Clear_Object(
		screen,
		BackGround,
		Dead_Bonus -> x,
		Dead_Bonus -> y - 1,
		0, 3
		);
	
	Dead_Bonus -> on = false;
	Dead_Bonus -> x  =COL - 10;
	
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


	SetColor(YELLOW, BackGround[70][0]);
	SetCursor (70, 0);
	printf("TANKS:%d", ++*tanks );
    sndPlaySound ("Explode.wav", SND_SYNC);
}