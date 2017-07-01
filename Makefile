##
## Makefile for Makefile in /home/hugo.varloud/ADM_calendar_2016
## 
## Made by hugo varloud
## Login   <hugo.varloud@epitech.net>
## 
## Started on  Sat Jul  1 10:55:21 2017 hugo varloud
## Last update Sat Jul  1 11:18:57 2017 romain pillot
##

CC	=	gcc

NAME	=	calendar

RM	=	rm -f

SRCS	=	src/main.c			\
		src/util.c			\
		src/sortbym.c			\
		src/sortbye.c			\
		src/employe.c			\
		src/meeting.c			\
		src/meeting_util.c		\
		src/tricky.c			\
		src/util/read.c			\
		src/util/array.c		\
		src/util/free.c			\
		src/util/str_starts.c		\
		src/util/tab_contains.c		\
		src/util/str_countchar.c	\
		src/util/str_duplicate.c	\
		src/util/str_equals.c		\
		src/util/str_length.c		\
		src/util/str_reduce.c		\
		src/util/str_split.c		\
		src/util/str_concat.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-Iinc -g3 #-Werror -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	find -name "*~" -delete -or -name "#*#" -delete

re: fclean all

.PHONY: all clean fclean re
