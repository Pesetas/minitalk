# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antramir <antramir@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 11:06:31 by antramir          #+#    #+#              #
#    Updated: 2023/03/10 01:47:13 by antramir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT			= ./libft/libft.a

SRCS			= ./src/server.c ./src/client.c
OBJS_SR			= ./src/server.o
OBJS_CL			= ./src/client.o


CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

all:			server client	

server: 		${OBJS_SR} 
				@make --no-print-directory -C libft
				$(CC) $(CFLAGS) -o $@ $< -L./libft -lft

client: 		${OBJS_CL}
				@make --no-print-directory -C libft
				$(CC) $(CFLAGS) -o $@ $< -L./libft -lft

clean:
				@$(MAKE) clean --no-print-directory -C ./libft
				${RM} ${OBJS_SR} ${OBJS_CL}

fclean:			clean
				@$(MAKE) fclean --no-print-directory -C ./libft
				${RM} server client 

re:				fclean all

.PHONY:			all clean fclean re
