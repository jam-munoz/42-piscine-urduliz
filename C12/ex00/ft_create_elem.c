/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamunoz <joamunoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:27:10 by joamunoz          #+#    #+#             */
/*   Updated: 2026/07/25 13:28:49 by joamunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *elem;

	elem = malloc(sizeof(t_list));
	elem->next = NULL;
	elem->data = data;
	return (elem);
}

/* #include <stdio.h>
int main(void)
{
	int data1 = 23;
	char data2[] = "papa";
	t_list *elem1 = ft_create_elem(&data1);
	t_list *elem2 = ft_create_elem(data2);

	printf("elem1: %d\n", *(int*)elem1->data);
	printf("elem2: %s\n", (char *)elem2->data);
	data1 = 8;
	printf("elem1: %d\n", *(int*)elem1->data);
} */
