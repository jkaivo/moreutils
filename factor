factor() {
	n=$1
	f=2

	printf '%d:' $n

	while [ $n -gt $f ]; do
		if [ $((n % f)) -eq 0 ]; then
			printf ' %d' $f
			n=$((n / f))
		else
			f=$((f + 1))
		fi
	done

	if [ $n -gt 1 ]; then
		printf ' %d' $n
	fi

	printf '\n'
}

for i in $*; do
	factor $i
done
