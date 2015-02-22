/***
*void openning
*
*Purpose:
*			 put the player in to the right mood,
*			 keyboard keys instruction.
*			 show high score,
*			 get the player name.			
*		 
*			
*Entry:
*			
*       
*Exit:
*			
*			
*********************************************/


#include "atari.h"




void openning (
			   short   BackGround[][ROW + 1],
			   short   HeadLine[],
			   SCORE   High_Score[],
			   char    New_Player[]
			   )
{
	FILE*   SC;//scores	
	FILE*   BG;//back ground
	FILE*   HL;//head line
	int     j;
	int     i;
	int     count =		0;
	char    ch;
	char    num[5];
	clock_t time =		0;
	 
	
	sndPlaySound ("space.wav", SND_ASYNC);
	
	//back ground file
	 BG = fopen("space.bin","rb");
	
	 fread (
		 BackGround,
			sizeof(short),
			COL * (ROW + 1),
			BG
			);				
	
	 fclose(BG);

	//print back ground.
	for (i =0; i < ROW + 1; i++)	
	{
		for (j = 0; j< COL; j++)
		{
			SetColor(0,BackGround[j][i]);
			putch(SPACE);
		}
	}
	//head line file.
	HL = fopen("head line.bin","rb");
			
	fread (
		HeadLine,
		sizeof(short),
		915,
		HL
		);				

	fclose(HL);

	//head line show.
	while (count < 394)// 394 is the number of color points.
	{
		if (time < clock())
		{		
			TIMER(time, 20)
			//print head line points by random.
			i = rand()%915;
			
			while (HeadLine[i] == 0)
				i = rand()%915;
			
			SetColor (0, HeadLine[i]);
			SetCursor(i / 15 + 14, i % 15); 
			putch(SPACE);
			
			fflush(stdin);
			//a point that was print
			//get zero in the head line arrey.
			//for beter result.
			HeadLine[i] = 0;
			count ++;	
		}
	}
	
	//read from score file.
	SC = fopen("scores.bin","rb");	
	fread (
		High_Score,
		sizeof(SCORE),
		8,
		SC
		);

	fclose(SC);
	
	//move  data. 
	for (count = 1; count <= 16; count++)
	{
		while (time > clock());
		TIMER(time, 100);		
		
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
			
		//PRINT PLAY KEY.
		Move_Object(
			BackGround,
			"SHOT ",
			PINK,
			50 - count, 17,
			5, 0
			);
		
		Move_Object(
			BackGround,
			&(ch = 30),
			PINK,
			51 - count,18,
			1, 0
			);
				
		Move_Object(
			BackGround,
			&(ch = SPACE),
			PINK,
			52 - count,18,
			1, 0
			);
	
		Move_Object(
			BackGround,
			"GO LEFT",
			PINK,
			42 - count,19,
			8, 0
			);
	    
		Move_Object(
			BackGround,
			&(ch = 17),
			PINK,
			49 - count,19,
			1, 0
			);

		Move_Object(
			BackGround,
			&(ch = SPACE),
			PINK,
			50 - count,19,
			1, 0
			);
		
		
		Move_Object(
			BackGround,
            &(ch = 16),
			PINK,
			53 - count,19,
			1, 0
			);
					
		Move_Object(
			BackGround,
            "GO RIGHT ",
			PINK,
			54 - count,19,
			9, 0
			);			
	}
	//name insert.
	SetCursor(25,23);
	puts ("PLEASE ENTER YOUR NAME:");
	
	//head line file.
	HL = fopen("head line.bin","rb");
			
	fread (
		HeadLine,
		sizeof(short),
		915,
		HL
		);				

	fclose(HL);
	//head line change color. 
	while(!kbhit())
	{	
		if (time < clock())
		{		
			time = (clock_t) 1000 * MilliSecond + clock();
			for ( i = 0; i < 915; i ++)
			{
				if(HeadLine[i] != 0)
				{
					HeadLine[i] -- ;
					
					if( HeadLine[i] < 9)
						HeadLine[i] = 11;
					
					SetColor (0, HeadLine[i]);
					SetCursor(i / 15 + 14, i % 15); 
					putch(SPACE);
				}
			}
		}
	}
	
	SetColor(YELLOW, DARK_BLUE);
	SetCursor(48,23);
	fgets (New_Player, 7, stdin);
	
	//by default
	if (New_Player[0] == 10 )
		strcpy(New_Player, "Player \0");
}