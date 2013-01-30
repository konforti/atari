
/***
*Atari.h -        
*
*Purpose:
*       Contains definitions/declarations for Atari "space invedars" game.
*
****************************************************************************/

#ifndef __ATARI_H__
#define __ATARI_H__


#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>


//TIMERS
#define TANK_SPEED   20
#define BOMB_SPEED   20
#define ROCKET_SPEED 50
#define ARROW_SPEED  20
#define BONUS_SPEED  100
#define MONSTER_DOWN 5000

//TIMERS MACROS
#define MilliSecond  (CLOCKS_PER_SEC / 1000)

#define TIMER(time, speed)\
		time = (clock_t) speed * MilliSecond + clock();

//KEYBOARD
#define RIGHT       77
#define LEFT        75
#define SHOT		72

//SCREEN SIZE
#define COL			80
#define ROW			23

//ASCII
#define ESC			27
#define ARROW_SIGN  30
#define SPACE		32
#define BOMB_SIGN   3

//TOOLS
#define TANK_ON		1
#define ARROW_ON	2
#define MONSTER_ON	3
#define BOMB_ON		4
#define BONUS_ON	5

//SCORE
#define TIE			0
#define WIN			1
#define LOOSE		2

//ARREYS
#define ARROW_SIZE	2
#define BOMB_SIZE	2
#define MONSTER_SIZE 45

//COLORS
#define BLACK       0
#define DARK_BLUE   1 
#define DARK_GREEN  2
#define TURQUOISE   3
#define DARK_RED    4
#define PURPLE      5
#define BROWN       6
#define LIGHT_GREY  7
#define DARK_GREY   8
#define LIGHT_BLUE  9
#define LIGHT_GREEN 10
#define AZURE       11
#define LIGHT_RED   12
#define PINK        13
#define YELLOW      14
#define WHITE       15

#define MON			0
#define	ARR			1
#define	BOM			2
#define	TAN			3
#define	BON			4


//STRUCTS
typedef struct 
{
	bool on;
	int  x;
	int  y;
} ARROW;

typedef struct 
{
	bool on;
	int  x;
	int  y;
} MONSTER;

typedef struct
{
	bool on;
	int  x;
	int  y;
} BOMB;

typedef struct
{
	char  name[8];
	short score;
}SCORE;



//FUNCTIONS DECLERS:

void       main ();

void       tank_define			(
								 short		screen[][ROW],
								 char		*tank_shape, int tank_x,
								 short		BackGround[80][ROW + 1],
								 short		Tools_Color[]
								 );

void       bonus_monster		(
								 MONSTER	*bonus,
								 short		BackGround[][ROW + 1],
								 short		screen[][ROW],
								 short		Tools_Color[]
								 );


int        drop_bombs			(
								 BOMB		*skad,
								 MONSTER	*monster_arrey,
								 int		*tank_x,
								 int		*tanks,
								 short		screen[][ROW],
								 char		*tank_shape,
								 short		BackGround[][ROW + 1],
								 short		Tools_Color[]
								 );

int		   drop_rocket			(
								 BOMB		*rocket,
								 int		*tank_x,
								 int		*tanks,
								 short		screen[][ROW],
								 char		*tank_shape,
								 short		BackGround[][ROW + 1],
								 short		Tools_Color[]
								 );

void       direction			(
								 char		key,
								 int		*tank_x,
								 char		*tank_shape,
								 short		screen[][ROW],
								 short		BackGround[][ROW + 1],
								 short		Tools_Color[]
								 );

void       shoting			    (
								 ARROW		arrow_arrey[],
								 short		screen[][ROW],
								 MONSTER	*monster_arrey,
								 BOMB		*skad,
								 int		*counter,
								 int		*monster_faster,
								 short		BackGround[][ROW + 1],
								 MONSTER	*bonus,
								 int		*tanks,
								 short		Tools_Color[]
								 );

void       monster_define       (
								 MONSTER	*monster_arrey,
						         char		*monster_shape,
							     short		screen[][ROW],
							     short		Background[][ROW + 1],
								 short		Tools_Color[],
								 int		level
								 );

int        monster_move         (
								 MONSTER	*monster_arrey,
								 char		*monster_shape,
							 	 short		screen[][ROW],
								 int		*newline,
								 short		BackGround[][ROW + 1],
								 short		Tools_Color[]
								 );

void       SetColor             (
								 int		forecolor,
								 int		backcolor
								 );

void       SetCursor			(
								 int		x,
								 int		y
								 );

char       Engine				(
								 int		*counter,
								 int		*tanks,
								 short		BackGround[][ROW + 1],
								 int		level
								 );

void       screen_location		(
								 short		screen[][ROW],
								 int		x,
								 int		y,
								 int		tool
								 );

void       hit_monster			(
								 short		screen[][ROW],
								 MONSTER	*monster_arrey,
								 int		Dead_Monster, 
								 ARROW		*Killing_Arrow,
								 int		*monster_faster,
								 int		*counter,
								 short		BackGround[][ROW + 1]
								 );

void       new_arrow_approval	(
								 short BackGround[][ROW + 1],
								 ARROW		arrow_arrey[],
								 int		*newarrow,
								 int		tank_x,
								 int		*counter
								 );

void       hit_bomb				(
								 short		screen[][ROW],
								 ARROW		*Killing_Arrow,
								 BOMB		*Dead_Skad,
								 short		BackGround[][ROW + 1]
								 );

void       BackGround_define	(
								 short		BackGround[][ROW + 1],
								 short		Tools_Color[],
								 int		*BOMBWAIT,
								 int		*MONSTERMOVE,
								 int		*BONUSWAIT,					   
								 int		level
								 );

void       Hit_Bonus			(
								 short		screen[][ROW],
				                 short		BackGround[][ROW + 1],
								 ARROW		*Killing_Arrow,
								 MONSTER	*Dead_Bonus,
								 int		*tanks
								 );

void 	   Clear_Object	    	(
								 short		screen[][ROW],
								 short		BackGround[][ROW + 1],
								 int		X,
								 int		Y,
								 int		Wide,
								 int		High
								 );

void	   Move_Object          (
								 short		BackGround[][ROW + 1],
						         char		*Shape,				  
						         int		Color,
						         int		X,
						         int		Y,
						         int		Wide,
						         int		High
								 );

void      bomber_choose        (
								MONSTER		*monster_arrey,
					            BOMB		*skad
								);

void	  openning			   (
								short       BackGround[][ROW + 1],
							    short		HeadLine[],
							    SCORE		High_Score[],
							    char		New_Player[]
								);

void      End_Of_Game		   (
								short		BackGround[][ROW + 1],
								SCORE		High_Score[],
								char        New_Player[],
								int		    counter
								);


#endif __ATARI_H__
