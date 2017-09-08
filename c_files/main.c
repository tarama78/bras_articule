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
	t_bras			bras;
	FILE			*ino;

	(void)argc;
	(void)argv;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
		return (EXIT_FAILURE);
	fen = SDL_SetVideoMode(500, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	joystick = SDL_JoystickOpen(0);
	printf("nb joystick : %d\n",SDL_NumJoysticks());
	SDL_JoystickEventState(SDL_ENABLE);

	ft_init_bras(&bras);
	if (argc > 1)
		ino = fopen(argv[1], "w");
	else
		ino = fopen(DEF_INO_PORT, "w");
	ft_send_data(&bras, ino);
	fclose(ino);
	while (bras.quit == 0)
	{
		if (argc > 1)
			ino = fopen(argv[1], "w");
		else
			ino = fopen(DEF_INO_PORT, "w");
		ft_event(event, &bras);
		ft_send_data(&bras, ino);
		fclose(ino);
	}

	SDL_JoystickClose(joystick);
	SDL_FreeSurface(fen);
	SDL_Quit();
	return (EXIT_SUCCESS);
}

void	ft_init_bras(t_bras *bras)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		bras->mot[i] = 0;
		bras->last_data[i] = 1;
	}
	bras->speed = 0;
	bras->quit = 0;
}

void	ft_send_data(t_bras *bras, FILE *ino)
{
	int		data[4];
	int		i;

	if (bras->quit == 1)
	{
		i = -1;
		while (++i < 4)
			data[i] = 0;
	}
	else
	{
		i = -1;
		while (++i < 4)
		{
			if (bras->mot[i] == STOP)
				data[i] = 0;
			else
			{
				if (bras->speed == 1)
					data[i] = 1;
				else if (bras->speed == 2)
					data[i] = 2;
				else if (bras->speed == 3)
					data[i] = 3;
				else
					data[i] = 0;
				if (data[i] != 0 && bras->mot[i] == RIGHT)
					data[i] += 3;
			}
		}

	}
	if (bras->last_data[0] != data[0] || bras->last_data[1] != data[1] ||
			bras->last_data[2] != data[2] || bras->last_data[3] != data[3])
	{
		fprintf(ino, "%d%d%d%d", data[0], data[1], data[2], data[3]);
		printf("send : %d%d%d%d\n", data[0], data[1], data[2], data[3]);
		i = -1;
		while (++i < 4)
			bras->last_data[i] = data[i];
	}
}
