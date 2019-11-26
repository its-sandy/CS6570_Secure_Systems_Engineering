all: hogwarts

hogwarts hogwarts_2019.c ./libmalloc.a:
	gcc hogwarts_2019.c -w -g -I. -L. libmalloc.a -lpthread -o quidditchteam

clean:
	rm -f *.o *.so *.*.diss *.diss
	rm -f quidditchteam
