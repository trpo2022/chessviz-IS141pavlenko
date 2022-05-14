.PHONY: clean bin/main
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

bin/main: obj/src/chessviz/main.o obj/src/libchessviz/libchess.a
	gcc $(CFLAGS) -o $@ $^

bin/test: obj/test/main.o obj/test/test.o obj/src/libchessviz/libchess.a
	gcc $(CFLAGS) -o $@ $^


obj/src/libchessviz/libchess.a: obj/src/libchessviz/check_mate.o obj/src/libchessviz/find_pos.o obj/src/libchessviz/move.o obj/test/test.o
	ar src $@ $^

obj/src/libchessviz/check_mate.o: src/libchessviz/check_mate.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I src/ -o $@ src/libchessviz/check_mate.c

obj/src/libchessviz/find_pos.o:  src/libchessviz/find_pos.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I src/ -o $@ src/libchessviz/find_pos.c

obj/src/libchessviz/move.o: src/libchessviz/move.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I src/ -o $@ src/libchessviz/move.c

obj/src/chessviz/main.o: src/chessviz/main.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I src/ -o $@ src/chessviz/main.c


obj/test/test.o: test/test.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I thirdparty/ -I src/ -o $@ $<

obj/test/main.o: test/main.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I thirdparty/ -I src/ -o $@ $<

run/main:
	./bin/main
	
run/test:
	./bin/test

clean:
	rm obj/src/chessviz/*.o
	rm obj/src/libchessviz/*.o
	rm obj/src/chessviz/*.d
	rm obj/src/libchessviz/*.d
	rm obj/test/*.o
	rm obj/test/*.d
