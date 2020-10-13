
cc = gcc
CFLAGS += -Wall -Wextra
TDFLAGS = -pthread

prodcom: prodcom.o reader.o munch1.o munch2.o writer.o queue.o statistic.o
	cc -o prodcom prodcom.o reader.o munch1.o munch2.o writer.o queue.o statistic.o $(CFLAGS) $(TDFLAGS)


prodcom.o: prodcom.c prodcom.h queue.h
	cc -c prodcom.c $(CFLAGS)


queue.o: queue.c queue.h statistic.h prodcom.h
	cc -c queue.c $(CFLAGS)


statistic.o: statistic.c statistic.h queue.h
	cc -c statistic.c $(CFLAGS)

reader.o: reader.c reader.h prodcom.h queue.h
	cc -c reader.c $(CFLAGS)


munch1.o: munch1.c munch1.h prodcom.h queue.h
	cc -c munch1.c $(CFLAGS)


munch2.o: munch2.c munch2.h prodcom.h queue.h
	cc -c munch2.c $(CFLAGS)


writer.o: writer.c writer.h prodcom.h queue.h statistic.h
	cc -c writer.c $(CFLAGS)

clean:
	rm prodcom prodcom.o reader.o munch1.o munch2.o writer.o queue.o
