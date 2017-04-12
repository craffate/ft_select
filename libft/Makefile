NAME		=	libft.a

SRCS		=	ft_putchar.c \
				ft_putstr.c \
				ft_strlen.c \
				ft_strdup.c \
				ft_strnew.c \
				ft_strjoin.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_putnbr.c \
				ft_atoll.c \
				ft_lltoa.c \
				ft_absval.c \
				ft_bzero.c \
				ft_factorial.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_lltoa_base.c \
				ft_memalloc.c \
				ft_memset.c \
				ft_memchr.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memcmp.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_putchar_fd.c \
				ft_lstnew.c \
				ft_lstmap.c \
				ft_lstiter.c \
				ft_lstadd.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_stackswap.c \
				ft_stackrotate.c \
				ft_stackrrotate.c \
				ft_stackpush.c \
				ft_stackpop.c \
				ft_stackpeek.c \
				ft_stackmove.c \
				ft_stackisempty.c \
				ft_stackisfull.c \
				ft_stacknew.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putwchar.c \
				ft_putwstr.c \
				ft_strclr.c \
				ft_strdel.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strcpy.c \
				ft_strcmp.c \
				ft_strlcat.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_wstrdup.c \
				ft_wcharlen.c \
				ft_wstrlen.c \
				ft_wstrcmp.c \
				ft_wstrjoin.c \
				ft_strncmp.c \
				ft_wstrncmp.c \
				ft_strcpy.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_ugetchar.c \
				ft_strsub.c \
				ft_strsplit.c \
				ft_strtrim.c \
				ft_strncat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strnequ.c \
				ft_wstrcat.c \
				ft_wstrnew.c \
				ft_wstrchr.c \
				ft_strpush.c \
				ft_stackprint.c \
				ft_atoi.c \
				ft_putstr_fd.c

GNL_SRCS	=	get_next_line.c

PRINTF_SRCS	=	ft_colors.c \
				ft_is.c \
				ft_is2.c \
				ft_parse.c \
				ft_preprocess.c \
				ft_preprocess2.c \
				ft_printf.c \
				ft_process.c \
				ft_process2.c \
				ft_process3.c \
				ft_save.c \
				ft_toolbox.c \
				ft_toolbox2.c

SRCS_PATH	=	./srcs

PRINTF_PATH	=	./ft_printf

GNL_PATH	=	./get_next_line

OBJS		=	$(addprefix srcs/, $(SRCS:.c=.o))

GNL_OBJS	=	$(addprefix get_next_line/, $(GNL_SRCS:.c=.o))

PRINTF_OBJS	=	$(addprefix ft_printf/, $(PRINTF_SRCS:.c=.o))

INCS		=	./includes

CC			=	clang

FLAGS		=	-Weverything

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(PRINTF_OBJS)
	ar -rcs $(NAME) $(OBJS) $(GNL_OBJS) $(PRINTF_OBJS)

$(SRCS_PATH)/%.o: $(SRCS_PATH)/%.c
	$(CC) $(FLAGS) -o $@ -c $< -I$(INCS)

$(GNL_PATH)/%.o: $(GNL_PATH)/%.c
	$(CC) $(FLAGS) -o $@ -c $< -I$(INCS)

$(PRINTF_PATH)/%.o: $(PRINTF_PATH)/%.c
	$(CC) $(FLAGS) -o $@ -c $< -I$(INCS)

clean:
	rm -f $(OBJS) $(GNL_OBJS) $(PRINTF_OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: clean
