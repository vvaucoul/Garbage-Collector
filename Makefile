# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 15:24:11 by vvaucoul          #+#    #+#              #
#    Updated: 2022/09/08 12:43:22 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include mk-dependencies/Colors.mk

ifeq ($(shell which valgrind 2>/dev/null),)
VALGRIND		=
else
VALGRIND		=	valgrind
endif

NAME			=	libvgcl.a

CC				=	clang-11
CFLAGS			=	-g3 -Wall -Wextra -MD -fPIE
INCLUDES		=	-I includes

SRCS_DIR 		=	srcs
SRCS 			=	$(SRCS_DIR)/garbage_collector.c \
					$(SRCS_DIR)/__local_garbage.c
OBJS 			=	$(SRCS:.c=.o)

SRCS_TEST_DIR	=	tests
SRCS_TEST		=	$(SRCS_TEST_DIR)/main.c
OBJS_TEST		=	$(SRCS_TEST:.c=.o)

DEPENDS			=	$(OBJS:.o=.d)
DEPENDS_TEST	=	$(OBJS_TEST:.o=.d)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(_LWHITE)Compiling: $(_LGREEN)%s $(_END)\n" $< 

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "$(_LWHITE)Creating Library: $(_LCYAN)%s $(_END)\n" $(NAME)

clean:
	@rm -f $(OBJS) $(OBJS_TEST) $(DEPENDS) $(DEPENDS_TEST)

fclean: clean
	@rm -f $(NAME)
	@rm -f test

re: fclean all

test: $(NAME) $(OBJS_TEST)
	@$(CC) $(INCLUDES) $(OBJS_TEST) -L $(NAME) $(NAME) -o test
	@printf "$(_LWHITE)Create binary: $(_LGREEN)%s $(_END)\n" test
	@$(VALGRIND) ./test

install: $(NAME)
	@cp $(NAME) /usr/local/lib/$(NAME)
	@printf "$(_LWHITE)Installing: $(_LGREEN)%s $(_END)\n" /usr/local/lib/$(NAME)
	@mkdir -p /usr/local/include/vgcl
	@cp includes/*.h /usr/local/include/vgcl
	@printf "$(_LWHITE)Installing: $(_LGREEN)%s $(_END)\n" /usr/local/include/vgcl
	@make -s -C . check-install

uninstall: 
	@rm -f /usr/local/lib/$(NAME)
	@rm -f /usr/local/include/vgcl/*.h
	@printf "$(_LWHITE)Uninstalling: $(_LGREEN)%s $(_END)\n" /usr/local/lib/$(NAME)
	@printf "$(_LWHITE)Uninstalling: $(_LGREEN)%s $(_END)\n" /usr/local/include/vgcl/*.h

check-install:
	@gcc -Wall -Wextra -Werror tests/check-install.c -lvgcl -o checker
	@./checker
	@rm -f checker && make -s -C . fclean

.PHONY: all clean fclean re test install uninstall check-install

-include $(DEPENDS)
-include $(DEPENDS_TEST)