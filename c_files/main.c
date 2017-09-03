/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 11:04:13 by tnicolas          #+#    #+#             */
/*   Updated: 2017/09/01 11:04:13 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <SDL/SDL.h>

#define STOP 0
#define LEFT 1
#define RIGHT 2
#define VAL_AX 10000

int main(int argc, char **argv)
{
	SDL_Event		event;
	SDL_Surface		*fen;
	SDL_Joystick	*joystick;
	int				quit;
	int				art1;
	int				art2;
	int				rotation;
	int				pince;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
		return EXIT_FAILURE;
	fen = SDL_SetVideoMode(500, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	joystick = SDL_JoystickOpen(0);
	printf("nb joystick : %d\n",SDL_NumJoysticks());
	SDL_JoystickEventState(SDL_ENABLE);

	quit = 0;
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
					rotation = LEFT;
					printf("rotation gauche %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 0 && event.jaxis.value > VAL_AX &&
						rotation != RIGHT)
				{
					rotation = RIGHT;
					printf("rotation droite %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 0 && event.jaxis.value < VAL_AX &&
						event.jaxis.value > -VAL_AX && rotation != STOP)
				{
					rotation = STOP;
					printf("stop rotation %d\n", event.jaxis.value);
				}
				if (event.jaxis.axis == 1 && event.jaxis.value < -VAL_AX &&
						art1 != LEFT)
				{
					art1 = LEFT;
					printf("art1 gauche %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 1 && event.jaxis.value > VAL_AX &&
						art1 != RIGHT)
				{
					art1 = RIGHT;
					printf("art1 droite %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 1 && event.jaxis.value < VAL_AX &&
						event.jaxis.value > -VAL_AX && art1 != STOP)
				{
					art1 = STOP;
					printf("stop art1 %d\n", event.jaxis.value);
				}
				if (event.jaxis.axis == 4 && event.jaxis.value < -VAL_AX &&
						art2 != LEFT)
				{
					art2 = LEFT;
					printf("art2 gauche %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 4 && event.jaxis.value > VAL_AX &&
						art2 != RIGHT)
				{
					art2 = RIGHT;
					printf("art2 droite %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 4 && event.jaxis.value < VAL_AX &&
						event.jaxis.value > -VAL_AX && art2 != STOP)
				{
					art2 = STOP;
					printf("stop art2 %d\n", event.jaxis.value);
				}
				if (event.jaxis.axis == 3 && event.jaxis.value < -VAL_AX &&
						pince != LEFT)
				{
					pince = LEFT;
					printf("pince gauche %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 3 && event.jaxis.value > VAL_AX &&
						pince != RIGHT)
				{
					pince = RIGHT;
					printf("pince droite %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 3 && event.jaxis.value < VAL_AX &&
						event.jaxis.value > -VAL_AX && pince != STOP)
				{
					pince = STOP;
					printf("stop pince %d\n", event.jaxis.value);
				}
				if (event.jaxis.axis == 2)
					printf("%d\n", event.jaxis.value);
				if (event.jaxis.axis == 5)
					printf("%d\n", event.jaxis.value);
				break;
			case SDL_JOYHATMOTION:
				if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_UP)
					printf("hat : SDL_HAT_UP\n");
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_DOWN)
					printf("hat : SDL_HAT_DOWN\n");
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_RIGHT)
					printf("hat : SDL_HAT_RIGHT\n");
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_LEFT)
					printf("hat : SDL_HAT_LEFT\n");
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_RIGHTDOWN)
					printf("hat : SDL_HAT_RIGHTDOWN\n");
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_RIGHTUP)
					printf("hat : SDL_HAT_RIGHTUP\n");
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_LEFTDOWN)
					printf("hat : SDL_HAT_LEFTDOWN\n");
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_LEFTUP)
					printf("hat : SDL_HAT_LEFTUP\n");
				else if(event.jhat.hat == 0 &&
						event.jhat.value == SDL_HAT_CENTERED)
					printf("hat : SDL_HAT_CENTERED\n");
				break;
		}
		SDL_Delay(1);
	}
	SDL_JoystickClose(joystick);
	SDL_FreeSurface(fen);
	SDL_Quit();
	return EXIT_SUCCESS;
}
