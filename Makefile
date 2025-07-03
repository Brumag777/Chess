CC = gcc
BASE_FLAGS = -Wall -Wextra -pedantic -O1 -g
SANITIZE_FLAGS = -fsanitize=address -fno-omit-frame-pointer
COVERAGE_FLAGS = --coverage
CFLAGS = $(BASE_FLAGS) $(SANITIZE_FLAGS) $(COVERAGE_FLAGS)
LDFLAGS = -lcunit

SRC = MiniJogo.c \
	  Interface/Comandos.c Interface/Imprime.c \
	  Logica/ComandosLogica.c Logica/ComandosLogicaA.c Logica/ComandosRestricoes.c \
	  Auxiliares/Template.c Auxiliares/Auxiliares.c Auxiliares/EncontrarJogadas.c Auxiliares/EncontrarAtaques.c Auxiliares/Cheque.c \
	  Memory/MemoryManagement.c Memory/Queue.c
OBJ = $(SRC:.c=.o)
MAIN_OBJ = Main.o $(OBJ)

all: Xadrez

Xadrez: $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f Jogo Testes *.o *.gcov *.gcda *.gcno \
		              Logica/*.o Logica/*.gcov Logica/*.gcda Logica/*.gcno \
					  Interface/*.o Interface/*.gcov Interface/*.gcda Interface/*.gcno \
					  Auxiliares/*.o Auxiliares/*.gcov Auxiliares/*.gcda Auxiliares/*.gcno \
					  Memory/*.o Memory/*.gcov Memory/*.gcda Memory/*.gcno