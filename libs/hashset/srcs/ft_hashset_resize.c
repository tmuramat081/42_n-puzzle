/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashset_resize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:07:42 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/24 00:07:42 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashset.h"

void	ft_hashset_resize(t_hashset *set)
{
	size_t	*tmp_data;
	size_t	tmp_cap;
	size_t	i;

	tmp_data = set->data;
	tmp_cap = set->cap;
	set->len += 1;
	set->cap = (size_t)(1 << set->nbits);
	set->mask = set->cap - 1;
	set->data = calloc(set->cap, sizeof(size_t));
	set->len = 0;
	i = 0;
	while (i < tmp_cap)
	{
		ft_hashset_insert(set, (void *)tmp_data[i]);
		i++;
	}
	free(tmp_data);
}
