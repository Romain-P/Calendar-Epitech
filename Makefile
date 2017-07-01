##
## Makefile for Makefile in /home/hugo.varloud/ADM_calendar_2016
## 
## Made by hugo varloud
## Login   <hugo.varloud@epitech.net>
## 
## Started on  Sat Jul  1 10:55:21 2017 hugo varloud
## Last update Sat Jul  1 11:10:45 2017 hugo varloud
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
		src/util/print.c		\
		src/util/read.c			\
		src/util/array.c		\
		src/util/list.c			\
		src/util/free.c			\
		src/util/nbr/nbr_parseint.c	\
		src/util/str/str_contains.c	\
		src/util/str/str_starts.c	\
		src/util/str/tab_sort.c		\
		src/util/str/tab_contains.c	\
		src/util/str/str_countchar.c	\
		src/util/str/str_duplicate.c	\
		src/util/str/str_equals.c	\
		src/util/str/str_length.c	\
		src/util/str/str_reduce.c	\
		src/util/str/str_split.c	\
		src/util/str/str_reverse.c	\
		src/util/str/str_concat.c	\
		src/util/str/str_isnumber.c	\
		src/util/str/str_replace.c	\
		src/util/str/str_ends.c

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
