/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:58:32 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/20 22:58:32 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_heap.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cast_d;
	unsigned char	*cast_s;

	if (!dst && !src)
		return (NULL);
	cast_d = (unsigned char *)dst;
	cast_s = (unsigned char *)src;
	while (n--)
		*(cast_d++) = *(cast_s++);
	return (dst);
}

static void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (!size)
		return (NULL);
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy (new_ptr, ptr, size);
	free(ptr);
	ptr = new_ptr;
	return (ptr);
}

int	ft_heap_realloc(t_heap *heap)
{
	void	**new_ptr;
	size_t	new_cap;

	new_cap = heap->cap * 2;
	new_ptr = (void **)ft_realloc(heap->data, sizeof(void *) * new_cap);
	if (!new_ptr)
		return (HEAP_FAILURE);
	heap->data = new_ptr;
	heap->cap = new_cap;
	return (HEAP_SUCCESS);
}
