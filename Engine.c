
/***
*char Engine
*
*Purpose:
*			define all definition by level.
*			run in unending loop and wait for interrupts,
*			by keyboard or by timers. act interrupts. 
*Entry:
*			int	   *counter              = number of point the player got.
*			int	   *tanks                = number of souls the player got.
*			short  BackGround[][ROW + 1] = numbers arrey that stand for back ground color.
*			int	   level                 = flag for level page.
*       
*Exit:
*			'w' for WIN   = continue to the next level.
*           'l' for LOOSE = end of game
*			
*******************************************************************************/
#include "atari.h"


char Engine (
			 int	*counter,
			 int	*tanks,
			 short  BackGround[][ROW + 1],
			 int	level
			 )
{
	BOMB    rocket;
	BOMB    skad;
    MONSTER bonus;
	MONSTER monster_arrey[MONSTER_SIZE]    = {0};
	ARROW   arrow_arrey[ARROW_SIZE]	       = {0};
	short   screen[COL][ROW]               = {0};	
	short   Tools_Color[5]                 = {0};
	clock_t tankSpeed				       =  0;
	clock_t arrowSpeed                     =  0;
	clock_t monsterMoveTime                =  0;
	clock_t bombSpeed                      =  0;
	clock_t bombWait                       =  0;
	clock_t bonusSpeed                     =  0;
	clock_t bonusWait                      =  0;
	clock_t rocketSpeed                    =  0;
	int     tank_x                         =  35;
	int     win_loose                      =  TIE;
	int     newarrow                       =  0 ;	           
	int     monster_faster                 =  0;
	int	    newline                        =  1;
	int		BOMB_WAIT					   =  0;
	int		MONSTER_MOVE				   =  0;	
	int		BONUS_WAIT					   =  0;
	char    key                            =  NULL;
    char    monster_shape [6]              =  {'\0'};
    char    tank_shape[6]	               =  {'\0'};	
	
	system ("cls");
	
	BackGround_define (
		BackGround,
		Tools_Color,	
		&BOMB_WAIT,
		&MONSTER_MOVE,
		&BONUS_WAIT,
		level
		);

	bonus.y	  =  2;
	bonus.x	  =  70;
	bonus.on  =  false;	
	skad.on   =  false;
	rocket.on =  false;
	TIMER(bonusWait, 20000);

	monster_define (
		monster_arrey,
		monster_shape,
		screen,
		BackGround,
		Tools_Color,
		level
		);	
	
	tank_define (
		screen,
		tank_shape,
		tank_x,
		BackGround,
		Tools_Color
		);
	
	SetColor (YELLOW, BackGround[0][0]);
	SetCursor (0, 0);
	printf("POINTS:%d",*counter);	
	
	SetCursor (70, 0);
	printf("TANKS:%d",*tanks);

	
	//unending loop
	while (key != ESC)
	{	
		//keyboard interrupts.
	 	if (kbhit())
		{
			key = getch();	
		
			if (key == -32)	
				key = getch();
			
			fflush(stdin);
				
			if (key == SHOT)//stdin
			{
				//approve new arrow.
				new_arrow_approval(
					BackGround,
					arrow_arrey,
					&newarrow,
					tank_x,
					counter
					);
			}	
			
			else if (tankSpeed < clock() &&
					 key == RIGHT || key == LEFT)
			{
				TIMER (tankSpeed, TANK_SPEED);
				// move the tank left/right.
				direction (
					key,
					&tank_x,
					tank_shape,
					screen,
					BackGround,
					Tools_Color
					);
			}
		}
		
		//go to shoting while there a still a arrow in the air.
		if (arrow_arrey[newarrow].on &&\
			arrowSpeed < clock())
		{

			TIMER(arrowSpeed, ARROW_SPEED);
			
			shoting(
				arrow_arrey,
				screen,
				monster_arrey,
				&skad,
				counter,
				&monster_faster,
				BackGround,
				&bonus,
				tanks,
				Tools_Color
				);
		}
		 // if its time go to move some monsters.
		if (monsterMoveTime < clock())
		{
			monsterMoveTime  = (clock_t) MONSTER_MOVE *\
				MilliSecond - (monster_faster) + clock();
			
			win_loose = monster_move(
				monster_arrey,
				monster_shape,
				screen,
				&newline,
				BackGround,
				Tools_Color
				);
					
			if (win_loose == WIN || win_loose == LOOSE)
				break;
		}
		
		// if its time for a new bonus turn one on.
		if (!bonus.on && bonusWait < clock())
		{
			TIMER(bonusWait, BONUS_WAIT);
			bonus.on = true;
		}
		
		//go while still there bonus flying.
		if (bonus.on && bonusSpeed < clock())
		{
			TIMER(bonusSpeed, BONUS_SPEED);
			
			bonus_monster(
				&bonus,
				BackGround,
				screen,
				Tools_Color
				);
		}
		// from level 2
		if (level > 1)
		{
			//if there no bomb on air and its time for new one
			if (!skad.on && bombWait < clock())
			{	
				TIMER(bombWait, BOMB_WAIT);
				
				// turn on on and choose the bomber.
				bomber_choose (
					monster_arrey,
					&skad
					);
					
			}
			
			//go while still a bomb on air.
			if (skad.on && bombSpeed < clock())
			{
				TIMER(bombSpeed, BOMB_SPEED);
				
				win_loose = drop_bombs (
					&skad,
					monster_arrey,
					&tank_x,
					tanks,
					screen,
					tank_shape,
					BackGround,
					Tools_Color
					);
			
			if (win_loose == WIN || win_loose == LOOSE)	
				break;
			}		
		}
		
		//from level 3.
		if (level > 2)
		{			
			//when the bonus monsetr find the tank unrder her,
			//she drop a guided rocket.			
			if (bonus.on && !rocket.on && bonus.x == tank_x)
			{
				rocket.on = true;
				rocket.x  = tank_x;
				rocket.y  = 3;
			}
			
			//the rocket run after the tank.
			//the only reason you can get away from it is 
			//because the tank run a little faster. 
			else if (rocket.on && rocketSpeed < clock())
			{
				TIMER(rocketSpeed, ROCKET_SPEED);
				
				win_loose = drop_rocket (
					&rocket,
					&tank_x,
					tanks,
					screen,
					tank_shape,
					BackGround,
					Tools_Color
					);
			
			if (win_loose == WIN || win_loose == LOOSE)	
				break;
			}
		}
	}
	if (win_loose == WIN)
		key = 'w';
	
	else if (win_loose == LOOSE)
		key = 'l';

	return key;
}


