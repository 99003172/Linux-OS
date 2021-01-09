all: server_code client_code

Server: server_code.c sc_header.h
	gcc -o server_code.out server_code.c -lrt
	
Client: client_code.c sc_header.h
	gcc -o client_code.out client_code.c -lrt
	
runClient:
	./client_code.out

runServer:
	./server_code.out

clean:
	rm -rf *.out *.o