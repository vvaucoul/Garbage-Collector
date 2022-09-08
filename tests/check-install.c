/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check-install.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:27:35 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/09/08 12:36:37 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vgcl/garbage_collector.h>
#include <stdio.h>
#include <string.h>

#define COLOR_LIGHT_GREEN "\033[92m"
#define COLOR_LIGHT_RED "\033[91m"
#define COLOR_RESET "\033[0m"
#define __STR__ ((char *)"SUCESS !")

int main(void)
{
    void *ptr;

    ptr = vmalloc(sizeof(char) * strlen(__STR__));
    if (ptr == NULL)
    {
        printf(COLOR_LIGHT_RED "FAILED !" COLOR_RESET "\n");
        return (0);
    }
    strcpy(ptr, __STR__);
    printf(COLOR_LIGHT_GREEN "%s\n" COLOR_RESET, (char *)ptr);
    vfree(ptr);
    return (0);
}