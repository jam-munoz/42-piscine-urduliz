/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:28:20 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/26 14:50:33 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;
	t_list	*p;

	i = 0;
	p = begin_list;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

/* #include <stdio.h>

t_list	*ft_create_elem(void *data)
{
	t_list *elem;

	elem = malloc(sizeof(t_list));
	elem->next = NULL;
	elem->data = data;
	return (elem);
}

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *push;
	push = ft_create_elem(data);
	push->next = *begin_list;
	*begin_list = push;
}

int main(void)
{
	t_list *list;

	list = NULL;
	ft_list_push_front(&list, "anonima");
	ft_list_push_front(&list, "sociedad ");
	ft_list_push_front(&list, "papas ");
	ft_list_push_front(&list, "las ");
	printf("%d\n", ft_list_size(list));
	return 0;
} */
