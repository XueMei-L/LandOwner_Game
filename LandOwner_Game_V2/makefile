main: main.o userInfo.o
	g++ -o main main.o userInfo.o

main.o: main.cpp
	g++ -c main.cpp

userInfo.o: userInfo.cpp
	gcc -c userInfo.cpp

clean:
	rm *.o main