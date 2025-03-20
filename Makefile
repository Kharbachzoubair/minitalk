CC = cc
CFLAGS = -Wall -Wextra -Werror -I./ft_printf

SERVER = server
CLIENT = client

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(FT_PRINTF) $(SERVER) $(CLIENT)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(SERVER): $(OBJS_SERVER) $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) $(FT_PRINTF)
	@echo "✅ Server compiled successfully!"

$(CLIENT): $(OBJS_CLIENT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) $(FT_PRINTF)
	@echo "✅ Client compiled successfully!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(FT_PRINTF_DIR)
	@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	@echo "🗑️  Cleaned object files."

fclean: clean
	@make fclean -C $(FT_PRINTF_DIR)
	@rm -f $(SERVER) $(CLIENT)
	@echo "🗑️  Fully cleaned build files."

re: fclean all
	@echo "🔄 Rebuilt everything!"
