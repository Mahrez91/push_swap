#include "push_swap.h"

stack   *ft_next_number(stack *pile)
{
    stack *tmp;

    tmp = pile;
    pile = pile->next;
    free(tmp);
    return (pile);
}

stack   *ft_swap(stack *pile)
{
    stack *element;

    element = initalisation(element);
    element = empiler(element, pile->value);
    pile = ft_next_number(pile);
    element = empiler(element, pile->value);
    pile = ft_next_number(pile);
    pile = empiler(pile, element->next->value);
    pile = empiler(pile, element->value);
    return (pile);
}

stack   *ft_add_back(stack **alst, stack *new)
{
    stack *tmp;

    tmp = *alst;
    while(tmp->next)
    {
        tmp = tmp->next; 
    }
    tmp->next = new;
    new->next = NULL;
    return (tmp);
}

stack   *ft_reverse(stack *pile)
{
    stack *element;
    stack *tmp;

    tmp = initalisation(tmp);
    element = initalisation(element);
    element = empiler(element, depiler(pile));
    pile = ft_next_number(pile);
    tmp = pile;
    pile = ft_add_back(&tmp, element);
    return (tmp);
}

stack *ft_add_front(stack **alst, stack *new)
{
    stack *tmp;

    tmp = initalisation(tmp);
    tmp = *alst;
    /*if(!(*alst))
    {
        *alst = new;
        return (*alst);
    }*/
    new->next = tmp;
    tmp = new;
    return(tmp);
}

stack   *ft_reverse_last(stack *pile)
{
    stack *element;
    stack *tmp;
    stack *final;

    final = initalisation(final);
    tmp = initalisation(tmp);
    element = initalisation(element);
    tmp = pile;
    while(tmp->next)
        tmp = tmp->next;
    while(pile->next)
    {
        element = empiler(element, pile->value);
        pile = ft_next_number(pile);
    }
    while(element)
    {
        final = empiler(final, element->value);
        element = ft_next_number(element);
    }
    final = ft_add_front(&final, tmp);
    return (final);
}

stack    *ft_swap_between(stack *pile_more, int add)
{
    stack *element;

    element = initalisation(element);
    element = empiler(element, add);
    pile_more = ft_add_front(&pile_more, element);
    return (pile_more);
}


void    tri_pile(stack *pileA, stack *pileB)
{
    printf("\nEtat de la pile A:\n");
    afficherPile(pileA);
    
    //printf("\nEtat de la pile B:\n");

    //printf("\nEtat de la pile B:\n");
    //afficherPile(pileB);
    
    //pileB=ft_swap_between(pileB, pileA->value);
    //pileA = ft_next_number(pileA);
    //pileA = ft_swap(pileA);

    //printf("\nEtat de la pile A:\n");
    //afficherPile(pileA);
    
    //pileA = ft_swap(pileA);
    //printf("\nEtat de la pile B:\n");
    //afficherPile(pileB);

    //printf("\nEtat de la pile A:\n");
    //afficherPile(pileA);

    pileA = ft_reverse_last(pileA);
    printf("\nEtat de la pile A:\n");
    afficherPile(pileA);
    //if(pileA->value > pileA->next->value)
    //printf("%d\n", element);
}