/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __local_garbage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:38:06 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/08/20 16:39:27 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <garbage_collector.h>

static GC *__create_new_element(void *ptr)
{
    GC *new_element;

    if ((new_element = malloc(sizeof(GC))) == NULL)
        return (NULL);
    new_element->ptr = ptr;
    new_element->next = NULL;
    return (new_element);
}

void __add_new_element(void *ptr)
{
    GC *new_element;

    new_element = __create_new_element(ptr);
    if (_g_gc == NULL)
        _g_gc = new_element;
    else
    {
        GC *tmp = _g_gc;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_element;
    }
}

void __delete_element(void *ptr)
{
    GC *tmp = _g_gc;
    GC *prev = NULL;

    while (tmp != NULL)
    {
        if (tmp->ptr == ptr)
        {
            if (prev == NULL)
                _g_gc = tmp->next;
            else
                prev->next = tmp->next;
            free(tmp->ptr);
            tmp->ptr = NULL;
            free(tmp);
            tmp = NULL;
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

void __delete_all(void)
{
    GC *tmp = _g_gc;
    GC *next;

    while (tmp != NULL)
    {
        next = tmp->next;
        if (tmp && tmp->ptr)
        {
            free(tmp->ptr);
            free(tmp);
        }
        tmp = next;
    }
}