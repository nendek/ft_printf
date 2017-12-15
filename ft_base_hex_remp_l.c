/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_remp3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 23:37:12 by arobion           #+#    #+#             */
/*   Updated: 2017/12/15 16:53:51 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_remp_hex_left_two(char *str, t_param param)
{
	if (param.precision >= (int)param.width)
		ft_remp_left_preci(str);
	else if (param.precision < (int)param.width)
		ft_remp_left_hex(str, param);
}

void			ft_remp_hex_left(char *str, \
		int i, t_param param, unsigned long long int var)
{
	char	*ret;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!(ret = ft_strdup(str)))
		return ;
	if (ft_is_in(param.flags, '#') && (var != 0 || param.conv == 'p'))
	{
		str[j++] = '0';
		str[j++] = 'x';
	}
	while (ret[k] != '\0')
	{
		str[k + j] = ret[k];
		k++;
	}
	free(ret);
	j = k + j;
	while (j < i)
		str[j++] = ' ';
	ft_remp_hex_left_two(str, param);
}

void		ft_remp_left_hex(char *str, t_param param)
{
	int		i;
	char	*tmp;
	int		diff;
	int		j;

	i = 0;
	j = 0;
	if (str[0] == '+' || str[0] == '-')
		j++;
	while (str[i + j] != ' ' && str[i + j] != '\0')
		i++;
	if (param.precision <= i)
		return ;
	diff = param.precision - i;
	tmp = ft_strdup(str);
	if (j == 1)
		diff++;
	i = j;
	while (i < diff)
		str[i++] = '0';
	while (tmp[j] != ' ')
		str[i++] = tmp[j++];
	free(tmp);
}
