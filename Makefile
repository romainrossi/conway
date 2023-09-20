all: conway

conway: conway.c evolve.h world.h
	gcc -Wall -Wextra -ggdb -o $@ $<

run: conway
	./conway

clean:
	rm conway

