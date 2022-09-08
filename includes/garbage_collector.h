/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:27:59 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/09/08 12:13:08 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GARBAGE_COLLECTOR_H
#define __GARBAGE_COLLECTOR_H

#include <stdlib.h>

typedef struct s_gc
{
    void *ptr;
    struct s_gc *next;
} t_gc;

#define GC t_gc
extern GC *_g_gc;

#define vmalloc(x) __gc_malloc(x)
#define vcalloc(n, x) __gc_calloc((n), (x))
#define vrealloc(p, x) __gc_realloc((p), (x))
#define vfree(p) __gc_free((p))
#define vdefragment() __gc_defragment()

extern void *__gc_malloc(size_t size);
extern void *__gc_calloc(size_t nmemb, size_t size);
extern void *__gc_realloc(void *ptr, size_t size);
extern void __gc_free(void *ptr);
extern void __gc_defragment(void);

extern void __add_new_element(void *ptr);
extern void __delete_element(void *ptr);
extern void __delete_all(void);

#ifndef __GARBAGE_COLLECTOR_CLEANUP
#define __GARBAGE_COLLECTOR_CLEANUP
#define gc_clean() __clean_all()

static inline void __clean_all(void)
{
    __delete_all();
}
#endif

#endif /* __GARBAGE_COLLECTOR_H */