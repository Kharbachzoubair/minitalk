CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client


SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

FT_PRINTF = ft_printf/libftprintf.a

all: $(FT_PRINTF) $(SERVER) $(CLIENT)

$(FT_PRINTF):
	make -C ./ft_printf

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) ./ft_printf/libftprintf.a

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) ./ft_printf/libftprintf.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	make clean -C ./ft_printf
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)


fclean: clean
	make fclean -C ./ft_printf
	rm -f $(SERVER) $(CLIENT)


re: fclean all