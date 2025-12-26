#-*-Makefile-*-

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCM = ./man/pipex.c ./man/pipex_utils.c ./man/pipex_utils1.c ./man/pipex_utils2.c ./man/ft_split.c ./man/ft_split_cpy.c ./man/ft_split_cpy_utils.c ./man/ft_strjoin.c \
		./man/ft_strlcat.c \

OBJM = $(SRCM:%.c=%.o)

SRCB = ./bonus/pipex_bonus.c ./bonus/pipex_bonus_utils.c ./bonus/pipex_bonus_utils1.c ./bonus/pipex_bonus_utils2.c ./bonus/ft_split_bonus.c \
		./bonus/ft_split_cpy_bonus.c ./bonus/ft_split_cpy_bonus_utils.c ./bonus/ft_strjoin_bonus.c \
		./bonus/ft_strlcat_bonus.c ./bonus/pipex_bonus_utils3.c ./bonus/gnl/get_next_line_utils.c ./bonus/gnl/get_next_line.c \
		./bonus/pipex_bonus_utils4.c \

OBJB = $(SRCB:%.c=%.o)

#binaries :
NAME = pipex
BONUS = ./bonus/pipex
HEADER_MAN = pipex.h
HEADER_BON = ./bonus/pipex_bonus.h

all: $(NAME) $(BONUS)
man: $(NAME)
bonus: $(BONUS)

#Build mandatory part :
$(NAME): $(OBJM)
	cc $(CFLAGS) $^ -o $@ 
# Compile object files for mandatory part :
pipex.o: pipex.c $(HEADER_MAN)
	$(CC) $(CFLAGS) -c $< -o $@

pipex_utils.o: pipex_utils.c $(HEADER_MAN)
	$(CC) $(CFLAGS) -c $< -o $@

pipex_utils1.o: pipex_utils1.c $(HEADER_MAN)
	$(CC) $(CFLAGS) -c $< -o $@

pipex_utils2.o: pipex_utils2.c $(HEADER_MAN)
	$(CC) $(CFLAGS) -c $< -o $@

ft_split.o: ft_split.c $(HEADER_MAN)
	$(CC) $(CFLAGS) -c $< -o $@

ft_split_cpy.o: ft_split_cpy.c $(HEADER_MAN)
	$(CC) $(CFLAGS) -c $< -o $@

ft_split_cpy_utils.o: ft_split_cpy_utils.c $(HEADER_MAN)
	$(CC) $(CFLAGS) -c $< -o $@

ft_strjoin.o: ft_strjoin.c $(HEADER_MAN)
	$(CC) $(CFLAGS) -c $< -o $@

ft_strlcat.o: ft_strlcat.c $(HEADER_MAN)
	$(CC) $(CFLAGS) -c $< -o $@

#Build bonus part :
$(BONUS): $(OBJB)
	cc $(CFLAGS) $^ -o $@
# Compile object files for bonus part :
./bonus/pipex_bonus.o: ./bonus/pipex_bonus.c $(HEADER_BON)
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/pipex_bonus_utils.o: ./bonus/pipex_bonus_utils.c $(HEADER_BON)
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/pipex_bonus_utils1.o: ./bonus/pipex_bonus_utils1.c $(HEADER_BON)
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/pipex_bonus_utils2.o: ./bonus/pipex_bonus_utils2.c $(HEADER_BON)
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/ft_split_bonus.o: ./bonus/ft_split_bonus.c $(HEADER_BON)
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/ft_split_cpy_bonus.o: ./bonus/ft_split_cpy_bonus.c $(HEADER_BON)
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/ft_split_cpy_bonus_utils.o: ./bonus/ft_split_cpy_bonus_utils.c $(HEADER_BON)
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/ft_strjoin_bonus.o: ./bonus/ft_strjoin_bonus.c $(HEADER_BON)
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/ft_strlcat_bonus.o: ./bonus/ft_strlcat_bonus.c $(HEADER_BON)
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/pipex_bonus_utils3.o: ./bonus/pipex_bonus_utils3.c $(HEADER_BON)
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/gnl/get_next_line_utils.o: ./bonus/gnl/get_next_line_utils.c $(HEADER_BON)
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/gnl/get_next_line.o: ./bonus/gnl/get_next_line.c $(HEADER_BON)
	$(CC) $(CFLAGS) -c $< -o $@

./bonus/pipex_bonus_utils4.o: ./bonus/pipex_bonus_utils4.c $(HEADER_BON)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJM) $(OBJB)
fclean: clean
	rm -f $(NAME) $(BONUS)
re: fclean all 
