NAME		=	ft_select

SRCS_FILES	=	main.c signals.c lists.c term.c handlers.c print.c \
				utils.c move.c konami.c

LIBFT		=	libft.a

LIBFTPATH	=	./libft

CC			=	clang

NAZIFLAGS	=	-Weverything -Werror

FLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	-I./includes -I$(LIBFTPATH)/includes

EXTRALIBS	=	-ltermcap

SRCS		=	$(addprefix srcs/,$(SRCS_FILES))

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(INCLUDES) -L$(LIBFTPATH) -lft $(EXTRALIBS)

$(LIBFT):
	make -C $(LIBFTPATH)

clean:
	make clean -C $(LIBFTPATH)

fclean: clean
	make fclean -C $(LIBFTPATH)
	rm -f $(NAME)

re: fclean all

.PHONY: clean $(LIBFT)
