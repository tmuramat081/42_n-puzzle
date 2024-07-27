/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashset_modifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:04:58 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/23 23:04:58 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashset.h"

#define PRIME_1 73
#define PRIME_2 5009
#define RESIZE_THRESHOLD 0.8

static bool	is_over_load_factor(t_hashset *set)
{
	if ((double)set->cap * RESIZE_THRESHOLD <= set->len)
		return (true);
	return (false);
}

bool	ft_hashset_insert(t_hashset *set, void *data)
{
	size_t	value;
	size_t	i;

	if (is_over_load_factor(set) == true)
		ft_hashset_resize(set);
	value = (size_t)data;
	if (!value)
		return (false);
	i = set->mask & (PRIME_1 * value);
	while (set->data[i] != 0 && set->data[i] != 1)
	{
		if (set->data[i] == value)
			return (false);
		else
			i = set->mask & (i + PRIME_2);
	}
	set->len += 1;
	set->data[i] = value;
	return (true);
}
