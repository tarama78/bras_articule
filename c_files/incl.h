/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 10:39:45 by tnicolas          #+#    #+#             */
/*   Updated: 2017/09/06 10:39:45 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCL_H
# define INCL_H

#define VAL_AX 10000
#define SIZE_DATA 30
#define REFRESH_TIME 400
#define SUCCESS 0
#define ERROR 1

typedef enum	e_mot
{
	 STOP, LEFT, RIGHT
}				t_mot;

typedef struct	s_bras
{
	t_mot		rot;
	t_mot		art1;
	t_mot		art2;
	t_mot		pince;
	int			speed;
}				t_bras;

void	event(SDL_Event event, char *data, int *speed)

#endif
