CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address
LDFLAGS =-fsanitize=address


main:main.o
	g++ $(LDFLAGS)  main.o -o main
	./main


main.o:main.cpp
	g++ $(CFLAGS) -c main.cpp


re: clean main


clean:
	rm -f *.o main
