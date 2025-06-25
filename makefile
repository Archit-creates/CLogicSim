all:
	all:
	gcc -o logic_sim main.c parser.c logic.c dff.c -Wall

clean:
	rm -f logic_sim
