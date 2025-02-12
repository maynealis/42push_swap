/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:01:47 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/05 12:11:12 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Allocates and returns a new node. The member variable `content` is 
* initialized with the value of the parameter ’content’. The variable `next` 
* is initialized to NULL.
*
* @param content The content to create the node with.
* @return A pointer to the newly created node, or NULL if allocation fails.
* 
* @warning The memory allocated for the node using `malloc` must be freed
* by the caller using `free`.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
