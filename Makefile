.POSIX:

PROGRAMS=arch base64 factor hostid mktemp nproc pinky printenv readlink \
	seq shuf stdbuf sync tac uptime users vdir yes

all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS) *.o
