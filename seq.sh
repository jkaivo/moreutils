FIRST=1
INCREMENT=1

if [ $# -eq 3 ]; then
	FIRST=$1
	INCREMENT=$2
	LAST=$3
elif [ $# -eq 2 ]; then
	FIRST=$1
	LAST=$2;
elif [ $# -eq 1 ]; then
	LAST=$1
else
	printf 'use one of:\n'
	printf '\tseq LAST\n'
	printf '\tseq FIRST LAST\n'
	printf '\tseq FIRST INCREMENT LAST\n'
	exit 1
fi

i=$FIRST
while [ $i -lt $LAST ]; do
	printf '%d\n' $i
	i=$((i + INCREMENT))
done
