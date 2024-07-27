/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashset.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <mt15hydrangea@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:28:43 by tmuramat          #+#    #+#             */
/*   Updated: 2022/06/23 16:28:43 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHSET_H
# define FT_HASHSET_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_hashset {
	size_t	nbits;
	size_t	mask;
	size_t	*data;
	size_t	len;
	size_t	cap;
}	t_hashset;

t_hashset	*ft_hashset_init(void);
void		ft_hashset_delete(t_hashset *set);
bool		ft_hashset_insert(t_hashset *set, void *data);
void		ft_hashset_resize(t_hashset *set);

#endif