cake: dirinfo.o
	gcc dirinfo.o

dirinfo.o: dirinfo.c
	gcc -c dirinfo.c

run:
	./a.out

clean:
	rm *.o
	rm *.out