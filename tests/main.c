/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:36:52 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/08/20 16:37:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <garbage_collector.h>

#include <string.h>
#include <stdio.h>

int main(void)
{
    char *str = vmalloc(10);
    bzero(str, 10);
    strcpy(str, "Hello !");
    vmalloc(10);
    vmalloc(10);
    printf("%s\n", str);
    vfree(str);
    gc_clean();
    return (0);
}