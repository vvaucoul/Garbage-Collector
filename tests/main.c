/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:36:52 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/09/08 12:18:45 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <garbage_collector.h>

#include <string.h>
#include <stdio.h>

int main(void)
{
    char *str = vmalloc(10);
    bzero(str, 10);
    memcpy(str, "Hello !", 7);
    vmalloc(10);
    vmalloc(10);
    printf("%s\n", str);
    vfree(str);
    gc_clean();

    vmalloc(100);
    gc_clean();

    void *tmp = vmalloc(100);
    bzero(tmp, 100);
    memcpy(tmp, "Hello !", 7);
    vdefragment();
    printf("%s\n", (char *)tmp);
    gc_clean();

    return (0);
}