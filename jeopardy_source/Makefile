CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LFLAGS = 
LIBS = 
SOURCES = jeopardy.c questions.c players.c
OBJECTS = $(subst .c,.o,$(SOURCES))
EXE = jeopardy.exe
.PHONY: clean cleanup help

jeopardy.exe : jeopardy.o questions.o players.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@ 

%.o : %.c
	$(CC) $(CFLAGS) -c $< 

all : $(EXE)

# Use del command for Windows compatibility
clean:
	del /f /q $(OBJECTS) $(EXE) *~

# Use del command for Windows compatibility
cleanup:
	del /f /q $(OBJECTS) *~

help:
	@echo "Valid targets:"
	@echo "  all:    generates all binary files"
	@echo "  clean:  removes .o and .exe files"
	@echo "  cleanup: removes .o files"
