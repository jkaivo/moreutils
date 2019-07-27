.POSIX:

PROGRAMS=arch base64 factor hostid mktemp nproc printenv readlink \
	seq stdbuf sync tac uptime users vdir yes

all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS) *.o
