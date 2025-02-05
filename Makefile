all: run clean

run:
	g++ main.cpp -o app.out
	./app.out

clean:
	rm app.out