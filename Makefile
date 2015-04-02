all: test

fractions: fractions.c
	$(CC) -DTEST=1 $< -lm -o $@

test: fractions
	./fractions 3.14159265359 1000
	./fractions 1234.5678 100000
