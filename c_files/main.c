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
				if (event.jaxis.axis == 0 && event.jaxis.value < -6000 &&
						rotation != LEFT)
				{
					rotation = LEFT;
					printf("rotation gauche %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 0 && event.jaxis.value > 6000 &&
						rotation != RIGHT)
				{
					rotation = RIGHT;
					printf("rotation droite %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 0 && event.jaxis.value < 6000 &&
				event.jaxis.value > -6000 && rotation != STOP)
				{
					rotation = STOP;
					printf("stop rotation %d\n", event.jaxis.value);
				}
				if (event.jaxis.axis == 3 && event.jaxis.value < -6000 &&
						pince != LEFT)
				{
					pince = LEFT;
					printf("pince gauche %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 3 && event.jaxis.value > 6000 &&
						pince != RIGHT)
				{
					pince = RIGHT;
					printf("rotation droite %d\n", event.jaxis.value);
				}
				else if (event.jaxis.axis == 3 && event.jaxis.value < 6000 &&
				event.jaxis.value > -6000 && pince != STOP)
				{
					pince = STOP;
					printf("stop pince %d\n", event.jaxis.value);
				}
				break;
		}
		SDL_Delay(10);
	}
	SDL_JoystickClose(joystick);
	SDL_FreeSurface(fen);
	SDL_Quit();
	return EXIT_SUCCESS;
}
