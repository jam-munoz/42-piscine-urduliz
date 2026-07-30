/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:28:20 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/26 15:49:23 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr);
{

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

void ft_print_list(t_list *list)
{
	if (!list)
	{
		printf("NULL\n");
		return ;
	}
	printf("%s -> ", (char *)list->data);
	ft_print_list(list->next);
}

int main(void)
{
	t_list *list;
	t_list *p;
	list = NULL;
	ft_list_push_front(&list, "papas");
	ft_list_push_back(&list, "sociedad");
	ft_list_push_front(&list, "las");
	ft_list_push_back(&list, "anonima");
	ft_print_list(list);
	return 0;
} */
