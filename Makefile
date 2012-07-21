CC=g++
CFLAGS=-Wall -Wextra -ansi -pedantic -O3
OBJECTS=s3log2tab.o
EXE=s3log2tab
INSTALL=/usr/bin/install
INSTALLPATH=/usr/local/bin/

$(EXE) : $(OBJECTS)
	$(CC) -o s3log2tab $(OBJECTS)

s3log2tab.o : s3log2tab.cpp
	$(CC) -c -o s3log2tab.o $(CFLAGS) s3log2tab.cpp

.PHONY: test

all : 
	$(MAKE) $(EXE)

rebuild : 
	$(MAKE) clean
	$(MAKE) all

install :
	$(INSTALL) $(EXE) $(INSTALLPATH)

clean :
	rm $(EXE) $(OBJECTS)

test : all
	./test/test.sh
