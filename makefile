all: 
	gcc -g bitap.c
	./a.out file0.txt file2.txt
	./a.out file3.txt file2.txt
# ls.o: ls.cpp
#         g++ -c ls.cpp

clean:
	rm *.o ls