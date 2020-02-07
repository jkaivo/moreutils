.POSIX:

PROGRAMS=arch base64 factor hostid mktemp nproc pinky printenv readlink \
	seq shuf stat stdbuf sync tac uptime users vdir yes

all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS) *.o
