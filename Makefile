# Using prams given in csa-makefile
CC = gcc
WARNING_FLAGS = -Wall -Wextra
OPTS = -pthread
EXE = prodcom
SCAN_BUILD_DIR = scan-build-out

prodcom: prodcom.o reader.o munch1.o munch2.o writer.o queue.o statistic.o
	$(CC) $(OPTS) -o $(EXE) prodcom.o reader.o munch1.o munch2.o writer.o queue.o statistic.o


prodcom.o: prodcom.c prodcom.h queue.h
	$(CC) $(OPTS) $(WARNING_FLAGS) -c prodcom.c


queue.o: queue.c queue.h statistic.h prodcom.h
	$(CC) $(OPTS) $(WARNING_FLAGS) -c queue.c


statistic.o: statistic.c statistic.h queue.h
	$(CC) $(OPTS) $(WARNING_FLAGS) -c statistic.c

reader.o: reader.c reader.h prodcom.h queue.h
	$(CC) $(OPTS) $(WARNING_FLAGS) -c reader.c $(CFLAGS)


munch1.o: munch1.c munch1.h prodcom.h queue.h
	$(CC) $(OPTS) $(WARNING_FLAGS) -c munch1.c $(CFLAGS)


munch2.o: munch2.c munch2.h prodcom.h queue.h
	$(CC) $(OPTS) $(WARNING_FLAGS) -c munch2.c $(CFLAGS)


writer.o: writer.c writer.h prodcom.h queue.h statistic.h
	$(CC) $(OPTS) $(WARNING_FLAGS) -c writer.c $(CFLAGS)

clean:
	rm -f $(EXE) *.o
	rm -rf $(SCAN_BUILD_DIR)


scan-build: clean
	scan-build -o $(SCAN_BUILD_DIR) make

scan-view: scan-build
	firefox -new-window $(SCAN_BUILD_DIR)/*/index.html
