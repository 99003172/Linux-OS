SRC = *.c

INC = *.h

all: $(SRC)
	gcc $(SRC) $(INC) -lpthread -o a.out -lrt

run:
	./a.out

clean:
	rm -rf *.out *.o
