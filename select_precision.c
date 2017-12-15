/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:35:28 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/15 17:35:29 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int			ft_isflag(char c)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (g_tab_flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}
*/
static char	*ft_precision_bis(char *str, int *i)
{
	int		j;
	char	*ret;

	j = 0;
	(*i)++;
	while (ft_isdigit(str[*i]) == 1)
	{
		(*i)++;
		j++;
	}
	if (!(ret = ft_strnew(j)))
		return (0);
	(*i)--;
	j--;
	while (j >= 0)
		ret[j--] = str[(*i)--];
	return (ret);
}

int			ft_precision(char *str, int *i, t_param *param)
{
	int		j;
	char	*ret;

	j = 0;
	while (str[*i] != '\0')
		(*i)++;
	while (*i >= 0)
	{
		if (str[*i] == '.')
		{
			if (!(ret = ft_precision_bis(str, i)))
				return (0);
			param->precision = ft_atoi(ret);
			free(ret);
			return (1);
		}
		(*i)--;
	}
	return (1);
}
