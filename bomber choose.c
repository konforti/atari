
/***
*void bomber_choose
*
*Purpose:
*			coose by random the monster who drop the next bomb.
*
*Entry:
*       
*Exit:
*
****************************************************************/


#include "atari.h"




void bomber_choose (
					MONSTER *monster_arrey,
					BOMB *skad
					)
{
	int		boom = 0;


	boom = rand()%MONSTER_SIZE;
	while (monster_arrey [boom].on == false)
		boom = rand()%MONSTER_SIZE;
	
	skad -> x  = monster_arrey [boom].x;
	skad -> y  = monster_arrey [boom].y;
	skad -> on = true;
    sndPlaySound ("Whoosh.wav", SND_ASYNC);
}