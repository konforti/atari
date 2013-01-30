
/***
*void main ()
*
*Purpose:
*			the cover to the program - run the openning page,      
*       
*			the engine by levels, while check if to continue or end of game
*       
*			between levels. run the end of game page.
*
****************************************************************************/


#include "atari.h"

void main ()
{
	unsigned char	key                         = {'Y'};
	int				level						;
	int				counter						;                      
	int				tanks						;                         
	SCORE			High_Score[8]				;
	char			New_Player[8]			    = {'\0'};
	short			HeadLine  [1088]            = {0};
	short			BackGround[COL][ROW + 1]    = {0};
	
	srand((unsigned)time(NULL));
	
	// open page.
    openning (BackGround, HeadLine, High_Score, New_Player);
	
	while (key == 'Y')
	{
		counter = 0;
		tanks   = 3;

		for (level = 1 ; level <= 3 && key != 'l' && key != ESC ; level ++)
		{
			//play mode by level .	
			key = Engine (
				&counter,
				&tanks,
				BackGround,
				level
				);
	
		}

		//ending page.
		End_Of_Game (BackGround, High_Score, New_Player, counter);
		
	
		
		key = getch();
		key = toupper(key);
		while (key != 'N'&& \
			   key != 'Y')
		{
			   key = getch();
			   key = toupper(key);
		}
		SetCursor (30, 23);
	}

	//stop all sounds before quit.
    sndPlaySound (NULL, SND_ASYNC);
}