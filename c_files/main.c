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

int main(int argc, char **argv)
{
	if(SDL_Init(SDL_INIT_JOYSTICK) < 0)
	// initialise juste le joystick (pas besoin d'une fenêtre pour nos tests)
		return EXIT_FAILURE;
	printf("Il y a %d joysticks.",SDL_NumJoysticks());
	// on écrit combien il y a de joysticks
	SDL_Quit();
	return EXIT_SUCCESS;
}
