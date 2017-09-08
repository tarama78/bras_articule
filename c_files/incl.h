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

#define DEF_INO_PORT "/dev/ttyACM0"
#define VAL_AX 10000
#define VAL_VIT_1 100
#define VAL_VIT_2 15000
#define VAL_VIT_3 32000
#define SIZE_DATA 30
#define REFRESH_TIME 50
#define SUCCESS 0
#define ERROR 1

typedef enum	e_mot
{
	 STOP, LEFT, RIGHT
}				t_mot;

typedef struct	s_bras
{
	t_mot		mot[4];
	int			last_data[4];
	int			all_off;
	int			speed;
	int			quit;
}				t_bras;

void	ft_init_bras(t_bras *bras);
void	ft_send_data(t_bras *bras, FILE *ino);
void	ft_event(SDL_Event event, t_bras *bras);

#endif
