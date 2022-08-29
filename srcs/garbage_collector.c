/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:27:41 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/08/20 16:35:09 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <garbage_collector.h>
#include <stdio.h>

GC *_g_gc = NULL;

extern void *__gc_malloc(size_t size)
{
    void *ptr;

    printf("Add new element\n");
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
    free(ptr);
}
