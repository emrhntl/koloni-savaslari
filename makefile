all:derle bagla calistir
derle:
	gcc -c -I "./include" ./src/uretimA.c -o ./lib/uretimA.o
	gcc -c -I "./include" ./src/uretimB.c -o ./lib/uretimB.o
	gcc -c -I "./include" ./src/uretim.c -o ./lib/uretim.o
	gcc -c -I "./include" ./src/taktik.c -o ./lib/taktik.o
	gcc -c -I "./include" ./src/taktikA.c -o ./lib/taktikA.o
	gcc -c -I "./include" ./src/taktikB.c -o ./lib/taktikB.o
	gcc -c -I "./include" ./src/koloni.c -o ./lib/koloni.o
	gcc -c -I "./include" ./src/oyun.c -o ./lib/oyun.o
	gcc -c -I "./include" ./src/test.c -o ./lib/test.o
bagla:
	gcc ./lib/oyun.o ./lib/uretim.o ./lib/uretimB.o ./lib/uretimA.o ./lib/taktik.o ./lib/taktikA.o ./lib/taktikB.o ./lib/koloni.o ./lib/test.o -o ./bin/program
calistir:
	./bin/program