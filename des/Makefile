CC=g++
CFLAGES=-Wall -g -O2
LIBS=-lcrypto

all:des des_ecb des_cbc

des:
	$(CC) $(CFLAGS) des.c -o $@ $(LIBS)

des_ecb:
	$(CC) $(CFLAGS) des_ecb.c hex.c -o $@ $(LIBS)

des_cbc:
	$(CC) $(CFLAGS) des_cbc.c hex.c -o $@ $(LIBS)
