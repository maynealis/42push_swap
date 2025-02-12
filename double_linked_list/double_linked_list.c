#include <stdio.h> //TODO printf
#include <stdlib.h> //malloc
#include "push_swap.h"

int	ft_stacksize(t_stack *stack)
{
	t_stack	*first;
	int		size;

	if (!stack)
		return (0);
	first = stack;
	size = 1;
	while (stack)
	{
		stack = stack->next;
		if (stack == first)
			break ;
		size++;
	}
	return (size);
}

t_stack	*ft_stacknew(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->num = number;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack *first;
	t_stack *last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	first = *stack;
	last = first->prev;
	last->next = new;
	first->prev = new;
	new->next = first;
	new->prev = last; 
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	t_stack *first;
	t_stack *last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	first = *stack;
	last = first->prev;
	new->next = first;
	new->prev = last;
	first->prev = new;
	last->next = new;
	*stack = new;
}

t_stack	*ft_stackremove_front(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;
	
	if(!stack || !*stack)
		return (NULL);
	first = *stack;
	second = first->next;
	last = first->prev;
	first->next = NULL;
	first->prev = NULL;
	if (second == first)
	{
		*stack = NULL;
		return (first);
	}
	second->prev = last;
	last->next = second;
	*stack = second;
	return (first);
}

//TODO: revisar esto
void	ft_stackfree(t_stack **stack)
{
	t_stack	*next;
	int		size;
	int		i;

	if (!stack)
		return ;
	size = ft_stacksize(*stack);
	i = 0;
	while (i < size)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
		i++;
	}
	*stack = NULL;
}

void	print_stack(t_stack *stack)
{
	t_stack *first;

	first = stack;
	while (stack)
	{
		printf("%i\n", stack->num);
		stack = stack->next;
		if (stack == first)
			break ;
	}
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*node;

	if (!src || !dst || !*src)
		return ;
	node = ft_stackremove_front(src);
	ft_stackadd_front(dst, node);
}

void	rotate(t_stack **stack)
{
	*stack = (*stack)->next;
}

void	reverse_rotate(t_stack **stack)
{
	*stack = (*stack)->prev;
}

void	swap(t_stack **stack)
{
	t_stack	*first;

	if (!stack || !*stack || ft_stacksize(*stack) < 2)
		return ;
	first = ft_stackremove_front(stack);
	rotate(stack);
	ft_stackadd_front(stack, first);
	reverse_rotate(stack);
}

int	get_max_num(t_stack *stack)
{
	t_stack	*first;
	int		max;

	first = stack;
	max = first->num;
	while (stack)
	{
		stack = stack->next;
		if (stack == first)
			break ;
		if (stack->num > max)
			max = stack->num;
	}
	return (max);
}

int	get_pos_max_num(t_stack *stack)
{
	t_stack	*first;
	int		max;
	int		pos;
	int		i;

	first = stack;
	max = first->num;
	pos = 0;
	i = 0;
	while (stack)
	{
		stack = stack->next;
		if (stack == first)
			break ;
		if (stack->num > max)
		{
			max = stack->num;
			pos = i;
		}
		i++;
	}
	return (pos);
}

char	is_reverse_sorted(t_stack *stack)
{
	int	max;
	int	size;
	int	i;

	max = get_max_num(stack);
	while (stack->num != max)
		stack = stack->next;
	size = ft_stacksize(stack);
	i = 0;
	while (i < size)
	{
		if (stack->next->num  > stack->num)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

// void	sort_three(t_stack **stack)
// {
// 	if (!is_reverse_sorted(*stack))
// 	{
// 		//TODO: print el mov
// 		swap(stack);
// 	}
// }

void	get_max_on_top(t_stack **stack)
{
	int	pos;
	int	size;
	int	i;

	pos = get_pos_max_num(*stack);
	size = ft_stacksize(*stack);
	if (pos <= size / 2)
	{
		i = 0;
		while (i < pos)
		{
			// TODOft_printf("rotate\n");
			rotate(stack); 
			i++;
		}
	}
	else
	{
		i = size;
		while (i > pos)
		{
			// TODOft_printf("reverse rotate\n");
			reverse_rotate(stack); 
			i--;
		}
	}
}

int	moves_with_rotate(int n, t_stack *stack)
{
	int	size;
	int	i;
	int	moves;

	i = 0;
	size = ft_stacksize(stack);
	moves = 0;
	while (i < size)
	{
		if (stack->prev->num < stack->num && (n > stack->num || n < stack->prev->num))
		{
			//push
			moves += 1;
			break ;
		}
		else if (stack->prev->num > stack->num && n > stack->num && n < stack->prev->num)
		{
			//push
			moves += 1;
			break ;
		}
		else
		{
			//rotate
			moves+=1;
		}
	}
	return (moves);
}

/*
int	main(void)
{
	t_stack	*a1 = NULL;
	t_stack *b1 = NULL;

	ft_stackadd_front(&a1, ft_stacknew(3));
	printf("size of a is %i\n", ft_stacksize(a1));
	print_stack(a1);

	ft_stackadd_back(&a1, ft_stacknew(1));
	printf("size of a is %i\n", ft_stacksize(a1));
	print_stack(a1);

	ft_stackadd_front(&a1, ft_stacknew(7));
	printf("size of a is %i\n", ft_stacksize(a1));
	print_stack(a1);

	printf("max %i\n", get_max_num(a1));
	
	ft_stackfree(&a1);
	ft_stackfree(&b1);
	return (0);
}
*/