CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

main : main.c libchess.a
	gcc $(CFLAGS) -o $@ $^

	
libchess.a : check_mate.o find_pos.o move.o
	ar src libchess.a $^

check_mate.o : checkmate.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -o $@ /src/libchessviz/checkmate.c
	
find_pos.o : find_pos.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -o $@ /src/libchessviz/find_pos.c

move.o : move.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -o $@ /src/libchessviz/move.c

main.o : main.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -o $@ /src/chessviz/main.c 	
		
run:
	./bin/main

