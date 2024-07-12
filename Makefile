CC = gcc
BIN = atlas
MAIN = atlas.c
DECODE_PGM_PATH = ./libs/decoder/program/
DECODE_HEADER_PATH = ./libs/decoder/header/
VIEW_HEADER_PATH = ./libs/view/
CFLAGS = -Wno-implicit-function-declaration
OBJS = $(DECODE_HEADER_PATH)decode_head.o $(VIEW_HEADER_PATH)stdout_header.o $(DECODE_PGM_PATH)decode_PGM_x64.o $(VIEW_HEADER_PATH)stdout_pgm.o $(VIEW_HEADER_PATH)stdout_help.o
all: atlas

atlas: $(OBJS)
	@echo "object files prepared"
	@echo ""
	@echo "Linking objects into atlas"
	@$(CC) -c $(MAIN) -o atlas.o
	@$(CC) $(OBJS) atlas.o -o $(BIN)

clean:
	@rm atlas.o
	@rm $(OBJS)
	@rm $(BIN)