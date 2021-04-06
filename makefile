main: LandOwner.cpp LandOwner.h main.cpp
	g++ LandOwner.cpp main.cpp -o main

clean:
	rm *.o main