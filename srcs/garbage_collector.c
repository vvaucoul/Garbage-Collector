/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:27:41 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/09/08 12:19:00 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <garbage_collector.h>
#include <stdio.h>

GC *_g_gc = NULL;

extern void *__gc_malloc(size_t size)
{
    void *ptr;

    ptr = malloc(size);
    if (ptr == NULL)
        return (NULL);
    else
    {
        __add_new_element(ptr);
        return (ptr);
    }
}

extern void *__gc_calloc(size_t nmemb, size_t size)
{
    void *ptr;

    ptr = calloc(nmemb, size);
    if (ptr == NULL)
        return (NULL);
    else
    {
        __add_new_element(ptr);
        return (ptr);
    }
}

extern void *__gc_realloc(void *ptr, size_t size)
{
    void *new_ptr;

    new_ptr = realloc(ptr, size);
    if (new_ptr == NULL)
        return (NULL);
    else
    {
        __add_new_element(new_ptr);
        __delete_element(ptr);
        return (new_ptr);
    }
}

extern void __gc_free(void *ptr)
{
    __delete_element(ptr);
}

extern void __gc_defragment(void)
{
    GC *tmp = _g_gc;
    GC *next = NULL;
    GC *prev = NULL;

    while (tmp != NULL)
    {
        next = tmp->next;
        if (next != NULL)
        {
            if (tmp->ptr == next->ptr)
            {
                if (prev == NULL)
                    _g_gc = next;
                else
                    prev->next = next;
                free(tmp->ptr);
                free(tmp);
                tmp = next;
            }
            else
            {
                prev = tmp;
                tmp = next;
            }
        }
        else
            tmp = next;
    }
}