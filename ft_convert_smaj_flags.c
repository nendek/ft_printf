/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_smaj2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:44:35 by arobion           #+#    #+#             */
/*   Updated: 2017/12/15 17:03:19 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*ft_flags_smaj(int *str, t_param param)
{
	int		i;
	int		*tmp;

	tmp = ft_strdupw(str);
	i = 0;
	while (str[i] != 0)
		i++;
	if (param.precision > 0)
	{
		if ((int)param.width > param.precision)
			i = param.width;
		else
			i = param.precision;
	}
	else if ((int)param.width > i)
		i = param.width;
	if (!(str = malloc(sizeof(int) * i + 1)))
		return (NULL);
	str[i] = 0;
	if (ft_is_in(param.flags, '-'))
		ft_remp_smaj_left(str, tmp, i, param);
	else
		ft_remp_smaj_right(str, tmp, i, param);
	free(tmp);
	return (str);
}
