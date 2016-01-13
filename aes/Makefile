CC=g++
CFLAGS=-Wall -g -O2
LIBS=-lcrypto
 
all: aes
 
aes: aes.cpp
	$(CC) $(CFLAGS) aes.cpp -o $@ $(LIBS)
 
clean:
	 @rm -f aes
