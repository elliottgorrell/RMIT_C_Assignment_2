SOURCES=vm.c vm_menu.c vm_options.c vm_stock.c vm_coin.c utility.c
HEADERS=vm.h vm_menu.h vm_options.h vm_stock.h vm_coin.h utility.h vm_system.h
PROGRAM=vm
DEBUG=-g
FLAGS=-ansi -pedantic -Wall $(DEBUG)

TEST_SOURCES=test_main.c

all:
	gcc $(FLAGS) -o $(PROGRAM) $(SOURCES)

clean:
	rm $(PROGRAM)

archive:
	zip $(USER)-a2 $(SOURCES) $(HEADERS) Makefile	

run_tests:
	gcc -g -ansi -pedantic -Wall -o vm_stock.o -c vm_stock.c
	gcc -g -ansi -pedantic -Wall -o vm_system.o -c vm_system.c
	gcc -g -lcmocka -o test_suite $(TEST_SOURCES) vm_stock.o vm_system.o
	./test_suite
