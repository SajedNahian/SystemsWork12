cake: dirinfo.o
	gcc dirinfo.o

dirinfo.o: dirinfo.c
	gcc -c dirinfo.c

run:
	./a.out $(dir)

clean:
	rm *.o
	rm *.out