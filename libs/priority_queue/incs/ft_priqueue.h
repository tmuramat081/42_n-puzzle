/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_priqueue.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:05:33 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/20 11:05:33 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRIQUEUE_H
# define FT_PRIQUEUE_H

# define PRIQUEUE_SUCCESS 1
# define PRIQUEUE_FAILURE 0

# include <stdbool.h>
# include "ft_heap.h"

typedef struct s_priqueue {
	t_heap	*heap;
}	t_priqueue;

// ********** Constructor ********** //
t_priqueue	*ft_priority_queue_init(size_t cap,
				int (*cmp)(const void *, const void *));

// ********** Deconstructor ********** //
void		ft_priority_queue_delete(t_priqueue **queue);

// ********** Modifier ********** //
int			ft_priority_queue_push(t_priqueue *queue, void *data);
void		*ft_priority_queue_pop(t_priqueue *queue);

// ********** Other Utils ********** //
bool		ft_priority_queue_empty(t_priqueue *queue);
bool		ft_priority_queue_is_empty(t_priqueue *queue);
size_t		ft_priority_queue_size(t_priqueue *queue);
#endif