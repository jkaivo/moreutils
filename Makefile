.POSIX:

PROGRAMS=hostid mktemp sync

all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS) *.o
