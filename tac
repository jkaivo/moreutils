cat "$@" | awk "$(tail -n +3 $0)"
exit $?

{
	lines[NR] = $0;
}

END {
	for (i = NR; i > 0; i--) {
		print lines[i]
	}
}
