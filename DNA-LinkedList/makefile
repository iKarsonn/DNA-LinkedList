hepsi: derle calistir

derle: 
	g++ -I ./include/ -o ./lib/dna.o -c ./src/dna.cpp
	g++ -I ./include/ -o ./lib/gen.o -c ./src/gen.cpp
	g++ -I ./include/ -o ./lib/kromozom.o -c ./src/kromozom.cpp
	g++ -I ./include/ -o ./bin/main ./lib/dna.o ./lib/gen.o ./lib/kromozom.o ./src/main.cpp
calistir:
	./bin/main