/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_is_empty.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:39:40 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/10 10:39:40 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

bool	ft_deque_is_full(t_deque *deque)
{
	if (deque->len == deque->cap)
		return (true);
	return (false);
}

bool	ft_deque_is_empty(t_deque *deque)
{
	if (deque->len == 0)
		return (true);
	return (false);
}

size_t	ft_deque_size(t_deque *deque)
{
	return (deque->len);
}

//******** For debug ********//
void	ft_deque_status(t_deque *deque)
{
	puts("---deque status---");
	printf("data:%p\n", deque->data);
	printf("begin:%p\n", deque->begin);
	printf("end:%p\n", deque->end);
	printf("len:%ld\n", deque->len);
	printf("cap:%ld\n", deque->cap);
	printf("data_size:%ld\n", deque->data_size);
	puts("-----------------");
}
