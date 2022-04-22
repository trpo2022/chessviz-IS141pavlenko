.PHONY: clean bin/main
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

bin/main : obj/src/chessviz/main.o obj/src/libchessviz/libchess.a
	gcc $(CFLAGS) -o $@ $^

obj/src/libchessviz/libchess.a : obj/src/libchessviz/check_mate.o obj/src/libchessviz/find_pos.o obj/src/libchessviz/move.o
	ar src $@ $^

obj/src/libchessviz/check_mate.o : src/libchessviz/check_mate.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I src/ -o $@ src/libchessviz/check_mate.c

obj/src/libchessviz/find_pos.o :  src/libchessviz/find_pos.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I src/ -o $@ src/libchessviz/find_pos.c

obj/src/libchessviz/move.o : src/libchessviz/move.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I src/ -o $@ src/libchessviz/move.c

obj/src/chessviz/main.o : src/chessviz/main.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I src/ -o $@ src/chessviz/main.c

run:
	./bin/main
clean:
	rm obj/src/chessviz/*.o
	rm obj/src/libchessviz/*.o
	rm obj/src/chessviz/*.d
	rm obj/src/libchessviz/*.d
