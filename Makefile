#Makefile

main:   clean debug
	gcc -g -pthread -Wpedantic -Wall -std=c11 main.c list.c -o lista
#-Werror -pedantic-errors
clean:  
	rm -f lista

debug:
	clear
	@echo "Kompiluje"

r:
	@echo "Executing file" 
	./lista
	
val:
	valgrind  --leak-check=full ./lista