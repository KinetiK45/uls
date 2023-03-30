all: obj LIBMX create_lib

FLAGS = -Wall -Wextra -Werror -Wpedantic

obj:
	mkdir obj

LIBMX: object.o

object.o:
	clang $(FLAGS) -c src/*.c

create_lib:
	ar -src libmx.a *.o
	ranlib libmx.a
	mv *.o obj

uninstall:
	rm -rf obj
	rm *.a

clean:
	rm -rf src
	rm -rf inc

reinstall:
	make uninstall
	make
