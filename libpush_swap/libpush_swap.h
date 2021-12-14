/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:11:18 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/14 17:12:44 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_SWAP_H
# define LIBPUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "../../libft-1.4.1/libft.h"

typedef struct s_stack
{
	int		*num;
	size_t	top;
}	t_stack;

#endif