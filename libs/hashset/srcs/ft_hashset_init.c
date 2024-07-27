/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashset_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:04:35 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/23 23:04:35 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashset.h"

t_hashset	*ft_hashset_init(void)
{
	t_hashset	*new_set;

	new_set = calloc(1, sizeof(t_hashset));
	if (!new_set)
		return (NULL);
	new_set->nbits = 3;
	new_set->cap = (size_t)(1 << new_set->nbits);
	new_set->mask = new_set->cap - 1;
	new_set->data = calloc(new_set->cap, sizeof(size_t));
	if (!new_set->data)
	{
		free(new_set);
		return (NULL);
	}
	new_set->len = 0;
	return (new_set);
}
