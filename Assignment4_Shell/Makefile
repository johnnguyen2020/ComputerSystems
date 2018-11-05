CC = gcc
CCFLAGS = -std=c99

all : run

parse : parse.c
	$(CC) $(CCFLAGS) -o parse $<

shell : shell.c
	$(CC) -o shell $<

run : parse shell
	ls parse shell

clean :
	rm -rf parse shell parse_shell_output.log make_output.log

clean_prog :
	rm -rf parse shell