.POSIX:

PROGRAMS=hostid sync tac

all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS) *.o
