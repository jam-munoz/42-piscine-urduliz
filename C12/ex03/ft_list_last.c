/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:28:20 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/26 14:50:41 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_list_last(t_list *begin_list)
{
	t_list *p;

	p = begin_list;
	while(p->next)
	{
		p = p->next;
	}
	return (p);
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
	t_list *p;
	list = NULL;
	ft_list_push_front(&list, "anonima");
	ft_list_push_front(&list, "sociedad ");
	ft_list_push_front(&list, "papas ");
	ft_list_push_front(&list, "las ");
	p = ft_list_last(list);
	printf("%s\n", p->data);
	return 0;
} */
