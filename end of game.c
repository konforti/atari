
/***
*void End_Of_Game
*
*Purpose:
*			show the scoore of the player,
*			and insert it to the high score(write to score.bin file) if it fit.
*			show high score.
*Entry:
*
*       
*Exit:
*			
*******************************************************************************/

#include "atari.h"


void End_Of_Game (
				  short		BackGround[][ROW + 1],
				  SCORE		High_Score[],
				  char		New_Player[],
				  int		counter
				  )
{
	
	
	char    ch[] = {"YOUR SCORE IS :"};
	char    num[5] = {'\0'}; 
	int     size = 8;
	int     i;
	int     j;
	int     count;
	FILE*   SC;
	clock_t time;

	sndPlaySound ("space2.wav", SND_ASYNC);
	
	system ("cls");

	// print the last back ground agine.
	for (i =0; i < ROW + 1; i++)	
	{
		for (j = 0; j< COL; j++)
		{
		SetColor(0,BackGround[j][i]);
		putch(SPACE);
		}
	}
	
	//print the player ending score.
	Move_Object(
		BackGround,
		New_Player,
		PINK,
		30,
		15,
		strlen(New_Player) - 1,
		0
		);
	
	
	Move_Object (
		BackGround,
		ch,
		PINK,
		30,
		16,
		15, 0
		);

	Move_Object (
		BackGround,
		itoa(counter, num, 10),
		PINK,
		50,
		16,
		5, 0
		);
	
	// sort high score list by.
	for (i = 0; i < size && (counter < High_Score[i].score); i++);
	
	if (counter > High_Score[i].score)
	{
		for (j = size - 1; j >= i ;j--)
		{
			High_Score[j].score = High_Score[j - 1].score;
			
			strcpy (
				High_Score[j].name,
				High_Score[j - 1].name
				);
		}

		High_Score[i].score = counter;
		
		strcpy (
			High_Score[i].name,
			New_Player); 
	}

    // write to scores file.
	SC = fopen("scores.bin", "wb");
		
	fwrite (
		High_Score,
		sizeof(SCORE),
		8,
		SC);

	fclose(SC);	
 	
	// read from scores file.
	SC = fopen("scores.bin", "rb");
		
	fread (
		High_Score,
		sizeof(SCORE),
		8,
		SC
		);
	
	fclose(SC);

	//move data. 
	for (count = 1; count <= 16; count++)
	{
		while (time > clock());
		TIMER(time, 20);
		
		Move_Object(
			BackGround,
			("              "),
			PINK,
			0, (count - 1),
			14, 0
			);
				
		//print names & scores.
		for (j = 0; j < 8 ;j ++)
		{
			Move_Object(
				BackGround,
				("              "),
				PINK,
				0, (count + j),
				14, 0
				);
			
			Move_Object(
				BackGround,
				High_Score[j].name,
				PINK,
				0, (count + j ),
				strlen(High_Score[j].name) - 1, 0
				);
		
			itoa(
				High_Score[j].score,
				num,
				10
				);   
	   
			i = strlen(num) ;
		   
			Move_Object(
				BackGround,
				num,
				PINK,
				9, (count + j ),
				i, 0
				);
		}

		//new game option.
		Move_Object(
			BackGround,
			("NEW GAME ? (Y / N)"),
			PINK,
			30, (18),
			18, 0
			);		
	}
}