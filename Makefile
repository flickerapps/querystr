all:
	gcc querystr.h -o querystr
test:
	make all
	gcc private/init.c -o test
	./test
clean:
	rm test
	rm querystr
