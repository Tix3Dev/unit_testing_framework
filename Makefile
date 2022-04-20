CC = @gcc
CFLAGS = -O2 -g -fsanitize=undefined -D LOG_VERBOSE

SRC = $(shell find . -type f -name '*.c')
OBJ = $(SRC:.c=.c.o)
FINAL = unit_test

all: $(FINAL)
	@printf "Built: $<\n\n"

run: $(FINAL)
	./$<

%.c.o: %.c
	@printf "CC $<\n"
	$(CC) -c $(CFLAGS) $< -o $@

clean: $(OBJ)
	rm $^
	

$(FINAL): $(OBJ)
	@printf "Linking...\n"
	$(CC) $^ -lubsan -o $@
	@printf "Linking complete\n"
