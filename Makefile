#Makefile

main:   clean debug
	gcc -g -pthread -Wpedantic -Wall -std=c11 -Werror -pedantic-errors main.c list.c -o lista
clean:  
	rm -f lista

debug:
	clear
	@echo "Kompiluje"

