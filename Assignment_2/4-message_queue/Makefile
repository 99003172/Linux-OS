all: server_mq client_str

Server: server_mq.c server_client_mq.h
	gcc -o server_mq.out server_mq.c -lrt
	
Client: client_str.c server_client_mq.h
	gcc -o client_str.out client_str.c -lrt
	
runClient:
	./client_str.out

runServer:
	./server_mq.out

clean:
	rm -rf *.out *.o