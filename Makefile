all: demo

fractions: fractions.c
	$(CC) $< -lm -o $@

demo: fractions
	./fractions
