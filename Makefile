SOURCES=vm.c vm_menu.c vm_options.c vm_stock.c vm_coin.c utility.c
HEADERS=vm.h vm_menu.h vm_options.h vm_stock.h vm_coin.h utility.h vm_system.h
PROGRAM=vm
DEBUG=-g
FLAGS=-ansi -pedantic -Wall $(DEBUG)
BUILD_FOLDER=build

TEST_SOURCES=test_main.c

build:
	gcc $(FLAGS) -o $(BUILD_FOLDER)/$(PROGRAM) $(SOURCES)

run:
	gcc $(FLAGS) -o $(BUILD_FOLDER)/$(PROGRAM) $(SOURCES)
	build/vm stock.dat

clean:
	rm -r $(BUILD_FOLDER)

leak_check:
	valgrind --leak-check=full --show-reachable=yes build/vm stock.dat

archive:
	zip $(USER)-a2 $(SOURCES) $(HEADERS) Makefile	

run_tests:
	gcc -g -ansi -pedantic -Wall -o $(BUILD_FOLDER)/vm_stock.o -c vm_stock.c
	gcc -g -lcmocka -o $(BUILD_FOLDER)/test_suite $(TEST_SOURCES) $(BUILD_FOLDER)/vm_stock.o
	build/test_suite
