CC = g++ 
CFLAGS = -std=c++11

BigInt: BigInt.cpp
	$(CC) $(CFLAGS) BigInt.cpp -o BigInt
clean: 
	rm BigInt