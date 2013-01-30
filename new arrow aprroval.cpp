/***
*void new_arrow_approval 
*
*Purpose:
*			chack the arrow_arrey for new arrow condition.			
*			if true: initilaize a new arrow. 
*			
*Entry:
*			
*       
*Exit:
*			
*			
**********************************************************/

#include "atari.h"



void new_arrow_approval(
						short BackGround[][ROW + 1],
						ARROW	arrow_arrey[],
						int		*newarrow,
						int		tank_x,
						int     *counter
						)
{
		if (arrow_arrey[*newarrow].y < ROW - 15)
		{
				++ *newarrow;
					
				if (*newarrow >= (ARROW_SIZE))
						*newarrow = 0;
				
				if (!arrow_arrey[*newarrow].on)
				{
					arrow_arrey[*newarrow].on = true;
					arrow_arrey[*newarrow].x  = (tank_x);
					arrow_arrey[*newarrow].y  = (ROW - 1);
					
					sndPlaySound ("Laser.wav", SND_ASYNC);
					
					*counter -= 10;
					
					SetColor(YELLOW, BackGround[0][0]);
					SetCursor (0, 0);
					printf("POINTS:%d",*counter);
				}
		}
}