SERVER = server

CLIENT = client

all:
	gcc -Wall -Wextra -Werror server.c utils.c -o $(SERVER)
	gcc -Wall -Wextra -Werror client.c utils.c -o $(CLIENT)

clean:
	rm -rf client.o server.o utils.o

fclean: clean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re 