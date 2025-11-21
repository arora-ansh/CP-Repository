run: build
	./a.out

build:
	g++ -g solve.cpp -o a.out

clean:
	rm -f a.out solve.bin