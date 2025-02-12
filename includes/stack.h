/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:39:31 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/12 10:43:37 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		ft_stacksize(t_stack *stack);
t_stack	*ft_stacknew(int number);
void	ft_stackfree(t_stack **stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_stackremove_front(t_stack **stack);

// Operations with stack
int		get_max_num(t_stack *stack);
int		get_min_num(t_stack *stack);
int		get_pos_max_num(t_stack *stack);
int		get_pos_min_num(t_stack *stack);

// Check if is sorted
char	is_reverse_sorted(t_stack *stack);
char	is_sorted(t_stack *stack);

#endif
