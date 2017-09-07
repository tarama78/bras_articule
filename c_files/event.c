/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 10:27:35 by tnicolas          #+#    #+#             */
/*   Updated: 2017/09/06 10:27:35 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#include "incl.h"

void	ft_event(SDL_Event event, t_bras *bras)
{
	int		quit;
	clock_t	time_start;

	quit = 0;
	time_start = clock();
	while (quit == 0 || ((clock() - time_start) / 10) <
			(REFRESH_TIME + 10))
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_JOYBUTTONDOWN:
				//printf("bouton : %d\n", event.jbutton.button);
				switch (event.jbutton.button)
				{
					case 6 :
						quit = 1;
						bras->quit = 1;
						break;
				}
				break;
			case SDL_JOYAXISMOTION: //max 32768 min -32767
				if (event.jaxis.axis == 0 && event.jaxis.value < -VAL_AX &&
						bras->mot[0] != LEFT)
				{
					quit = 1;
					bras->mot[0] = LEFT;
					//printf("rotation gauche %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 0 && event.jaxis.value > VAL_AX &&
						bras->mot[0] != RIGHT)
				{
					quit = 1;
					bras->mot[0] = RIGHT;
					//printf("rotation droite %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 0 && event.jaxis.value < VAL_AX &&
						event.jaxis.value > -VAL_AX && bras->mot[0] != STOP)
				{
					quit = 1;
					bras->mot[0] = STOP;
					//printf("stop rotation %d\n", event.jaxis.value);
				}
				if (event.jaxis.axis == 1 && event.jaxis.value < -VAL_AX &&
						bras->mot[1] != LEFT)
				{
					quit = 1;
					bras->mot[1] = LEFT;
					//printf("bras->mot[1] gauche %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 1 && event.jaxis.value > VAL_AX &&
						bras->mot[1] != RIGHT)
				{
					quit = 1;
					bras->mot[1] = RIGHT;
					//printf("bras->mot[1] droite %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 1 && event.jaxis.value < VAL_AX &&
						event.jaxis.value > -VAL_AX && bras->mot[1] != STOP)
				{
					quit = 1;
					bras->mot[1] = STOP;
					//printf("stop bras->mot[1] %d\n", event.jaxis.value);
				}
				if (event.jaxis.axis == 4 && event.jaxis.value < -VAL_AX &&
						bras->mot[2] != LEFT)
				{
					quit = 1;
					bras->mot[2] = LEFT;
					//printf("bras->mot[2] gauche %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 4 && event.jaxis.value > VAL_AX &&
						bras->mot[2] != RIGHT)
				{
					quit = 1;
					bras->mot[2] = RIGHT;
					//printf("bras->mot[2] droite %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 4 && event.jaxis.value < VAL_AX &&
						event.jaxis.value > -VAL_AX && bras->mot[2] != STOP)
				{
					quit = 1;
					bras->mot[2] = STOP;
					//printf("stop bras->mot[2] %d\n", event.jaxis.value);
				}
				if (event.jaxis.axis == 3 && event.jaxis.value < -VAL_AX &&
						bras->mot[3] != LEFT)
				{
					quit = 1;
					bras->mot[3] = LEFT;
					//printf("bras->mot[3] gauche %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 3 && event.jaxis.value > VAL_AX &&
						bras->mot[3] != RIGHT)
				{
					quit = 1;
					bras->mot[3] = RIGHT;
					//printf("bras->mot[3] droite %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 3 && event.jaxis.value < VAL_AX &&
						event.jaxis.value > -VAL_AX && bras->mot[3] != STOP)
				{
					quit = 1;
					bras->mot[3] = STOP;
					//printf("stop bras->mot[3] %d\n", event.jaxis.value);
				}
				if (event.jaxis.axis == 2)
				{
					//quit = 1;
					//printf("%d\n", event.jaxis.value);
				}
				if (event.jaxis.axis == 5)
				{
					//printf("%d\n", event.jaxis.value);
					if (event.jaxis.value <= VAL_VIT_1 && bras->speed != 0)
					{
						quit = 1;
						bras->speed = 0;
					}
					else if (event.jaxis.value >= VAL_VIT_1 &&
							event.jaxis.value <= VAL_VIT_2 && bras->speed != 1)
					{
						quit = 1;
						bras->speed = 1;
					}
					else if (event.jaxis.value >= VAL_VIT_2 &&
							event.jaxis.value <= VAL_VIT_3 && bras->speed != 2)
					{
						quit = 1;
						bras->speed = 2;
					}
					else if (event.jaxis.value >= VAL_VIT_3 && bras->speed != 3)
					{
						quit = 1;
						bras->speed = 3;
					}
				}
				break;
			/*case SDL_JOYHATMOTION:
				if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_UP)
				{
					quit = 1;
					printf("hat : SDL_HAT_UP\n");
				}
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_DOWN)
				{
					quit = 1;
					printf("hat : SDL_HAT_DOWN\n");
				}
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_RIGHT)
				{
					quit = 1;
					printf("hat : SDL_HAT_RIGHT\n");
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_LEFT)
				{
					quit = 1;
					printf("hat : SDL_HAT_LEFT\n");
				}
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_RIGHTDOWN)
				{
					quit = 1;
					printf("hat : SDL_HAT_RIGHTDOWN\n");
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_RIGHTUP)
				{
					quit = 1;
					printf("hat : SDL_HAT_RIGHTUP\n");
				}
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_LEFTDOWN)
				{
					quit = 1;
					printf("hat : SDL_HAT_LEFTDOWN\n");
				}
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_LEFTUP)
				{
					quit = 1;
					printf("hat : SDL_HAT_LEFTUP\n");
				}
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_CENTERED)
				{
					quit = 1;
					printf("hat : SDL_HAT_CENTERED\n");
				}
				break;*/
		}
		SDL_Delay(1);
	}
}
