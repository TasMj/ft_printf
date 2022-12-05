# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 15:02:08 by tmejri            #+#    #+#              #
#    Updated: 2022/05/23 19:07:15 by tmejri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_fonctions.c ft_fonctions2.c ft_printf.c \

OBJS			= ${SRCS:.c=.o}

NAME			= libftprintf.a

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			${NAME}

${NAME}:		${OBJS}
						ar rcs ${NAME} ${OBJS}

clean:
						${RM} ${OBJS}

fclean:			clean
						${RM} ${NAME}

re:				fclean ${NAME}

bonus:			$(OBJS) $(BONUS_OBJS)
						ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re