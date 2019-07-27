readlink() {
	ls -l "$1" | awk -F' -> ' '{print $2}'
}

for i in "$@"; do
	readlink $i
done
