/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:01:56 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/16 18:12:49 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*ft_norme_for_index(stack *pileA, stack *tab, int tmp, int count)
{
	int		pos;
	stack	*element;
	stack	*tmp_elem;

	element = pileA;
	tmp_elem = pileA;
	while (count > 0)
	{
		pos = 1;
		tmp = ft_morceaux_suite(tmp_elem, tmp);
		while (element->value != tmp)
		{
			pos++;
			element = element->next;
		}
		element = pileA;
		tab = empiler(tab, pos);
		count--;
	}
	return (tab);
}

stack	*ft_index(stack *pileA, int count)
{
	stack	*tmp_elem;
	stack	*tab;
	int		tmp;
	int		pos;

	tab = NULL;
	tmp_elem = pileA;
	tmp = tmp_elem->value;
	tmp = ft_morceaux(tmp_elem, tmp);
	pos = 1;
	tmp_elem = pileA;
	while (tmp_elem->value != tmp)
	{
		pos++;
		tmp_elem = tmp_elem->next;
	}
	tab = empiler(tab, pos);
	tab = ft_norme_for_index(pileA, tab, tmp, count);
	return (tab);
}
