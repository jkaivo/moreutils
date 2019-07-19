.POSIX:

PROGRAMS=hostid sync

all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS) *.o
