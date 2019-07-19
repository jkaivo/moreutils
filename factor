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

if [ -z "$*" ]; then
	while IFS=\n read -r i; do
		factor $i
	done
else
	for i in $*; do
		factor $i
	done
fi
