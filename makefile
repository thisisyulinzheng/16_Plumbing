all: counter.c input.c 
	gcc -o counter.out counter.c
	gcc -o input.out input.c
run:
	./counter.out & ./input.out 