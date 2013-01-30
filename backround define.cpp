/***
*void BackGround_define
*
*Purpose:
*			define by levels - the back ground art paint.
*       
*			the color of the tools.
*       
*			set the timers.
*Entry:
*			 short	BackGround[][ROW + 1]	= Arrey equl to screen size,
*											  initialize from bin file.
*			 short	Tools_Color[]			= color box to be initialize.
*			 int	*BOMBWAIT				= timer tobe set.
*			 int	*MONSTERMOVE			= timer tobe set.
*			 int	*BONUSWAIT				= timer tobe set.				   
*			 int	level					= flag to level.
*      
*
**************************************************************************/


#include "atari.h"

void BackGround_define(
					   short	BackGround[][ROW + 1],
					   short	Tools_Color[],
					   int		*BOMB_WAIT,
					   int		*MONSTER_MOVE,
					   int		*BONUS_WAIT,					   
					   int		level
					   )
{
	int		i;
	int		j;
	FILE*	BG;

		if (level == 1)
		{
		BG = fopen("space.bin","rb");
			
			Tools_Color[MON] =  PINK;
			Tools_Color[ARR] =  AZURE;
			Tools_Color[TAN] =  LIGHT_GREY;
			Tools_Color[BON] = 	AZURE;
			
			*MONSTER_MOVE = 700;
			*BONUS_WAIT = 30000;
		
		}
		else if (level == 2)
		{
			BG = fopen("desert.bin","rb");
			
			Tools_Color[MON] =  BLACK;
			Tools_Color[ARR] =  BLACK;
			Tools_Color[BOM] =  DARK_BLUE;
			Tools_Color[TAN] =  DARK_GREY;
			Tools_Color[BON] = 	PINK;			
		
			*BOMB_WAIT = 1000;
			*MONSTER_MOVE = 700;
			*BONUS_WAIT = 20000;
		}
		
		else if (level == 3)
		{
			BG = fopen("underwater.bin","rb");
			
			Tools_Color[MON] =  DARK_BLUE;
			Tools_Color[ARR] =  BLACK;
			Tools_Color[BOM] =  BROWN;
			Tools_Color[TAN] =  DARK_GREY;
			Tools_Color[BON] = 	LIGHT_GREY;			
		
			*BOMB_WAIT = 500;
			*MONSTER_MOVE = 700;
			*BONUS_WAIT = 15000;
		}
		
		fread (
			BackGround,
			sizeof(short),
			COL * (ROW + 1),
			BG);				
			fclose(BG
				);

		
		for (i = 0; i < ROW + 1; i++)	
		{
			for (j = 0; j< COL; j++)
			{
				SetColor(0, BackGround[j][i]);
				putch(SPACE);
			}
		}
}      
		