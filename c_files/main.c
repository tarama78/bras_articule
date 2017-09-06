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
#include <time.h>
#include "incl.h"

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
	char			*data;
	int				speed;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
		return (EXIT_FAILURE);
	fen = SDL_SetVideoMode(500, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	joystick = SDL_JoystickOpen(0);
	printf("nb joystick : %d\n",SDL_NumJoysticks());
	SDL_JoystickEventState(SDL_ENABLE);

	if (!(data = malloc(sizeof(*data) * SIZE_DATA)))
		return (EXIT_FAILURE);
	event(event, time_start, data, &speed);

	SDL_JoystickClose(joystick);
	SDL_FreeSurface(fen);
	SDL_Quit();
	return (EXIT_SUCCESS);
}
