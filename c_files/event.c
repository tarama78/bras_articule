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

void	event(SDL_Event event, char *data, int *speed)
{
	int		quit;
	int		time_start;
	int		diff_time;

	quit = 0;
	time_start = clock() / CLOCKS_PER_SEC * 1000;
	*speed = -1;
	while (quit == 0)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_JOYBUTTONDOWN:
				printf("bouton : %d\n", event.jbutton.button);
				switch (event.jbutton.button)
				{
					case 6 :
						quit = 1;
						break;
				}
				break;
			case SDL_JOYAXISMOTION: //max 32768 min -32767
				if (event.jaxis.axis == 0 && event.jaxis.value < -VAL_AX &&
						rotation != LEFT)
				{
					quit = 1;
					rotation = LEFT;
					printf("rotation gauche %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 0 && event.jaxis.value > VAL_AX &&
						rotation != RIGHT)
				{
					quit = 1;
					rotation = RIGHT;
					printf("rotation droite %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 0 && event.jaxis.value < VAL_AX &&
						event.jaxis.value > -VAL_AX && rotation != STOP)
				{
					quit = 1;
					rotation = STOP;
					printf("stop rotation %d\n", event.jaxis.value);
				}
				if (event.jaxis.axis == 1 && event.jaxis.value < -VAL_AX &&
						art1 != LEFT)
				{
					quit = 1;
					art1 = LEFT;
					printf("art1 gauche %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 1 && event.jaxis.value > VAL_AX &&
						art1 != RIGHT)
				{
					quit = 1;
					art1 = RIGHT;
					printf("art1 droite %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 1 && event.jaxis.value < VAL_AX &&
						event.jaxis.value > -VAL_AX && art1 != STOP)
				{
					quit = 1;
					art1 = STOP;
					printf("stop art1 %d\n", event.jaxis.value);
				}
				if (event.jaxis.axis == 4 && event.jaxis.value < -VAL_AX &&
						art2 != LEFT)
				{
					quit = 1;
					art2 = LEFT;
					printf("art2 gauche %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 4 && event.jaxis.value > VAL_AX &&
						art2 != RIGHT)
				{
					quit = 1;
					art2 = RIGHT;
					printf("art2 droite %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 4 && event.jaxis.value < VAL_AX &&
						event.jaxis.value > -VAL_AX && art2 != STOP)
				{
					quit = 1;
					art2 = STOP;
					printf("stop art2 %d\n", event.jaxis.value);
				}
				if (event.jaxis.axis == 3 && event.jaxis.value < -VAL_AX &&
						pince != LEFT)
				{
					quit = 1;
					pince = LEFT;
					printf("pince gauche %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 3 && event.jaxis.value > VAL_AX &&
						pince != RIGHT)
				{
					quit = 1;
					pince = RIGHT;
					printf("pince droite %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 3 && event.jaxis.value < VAL_AX &&
						event.jaxis.value > -VAL_AX && pince != STOP)
				{
					quit = 1;
					pince = STOP;
					printf("stop pince %d\n", event.jaxis.value);
				}
				if (event.jaxis.axis == 2)
				{
					quit = 1;
					printf("%d\n", event.jaxis.value);
				}
				if (event.jaxis.axis == 5)
				{
					quit = 1;
					printf("%d\n", event.jaxis.value);
				}
				break;
			case SDL_JOYHATMOTION:
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
				break;
		}
		SDL_Delay(1);
	}
}
