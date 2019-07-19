cat "$@" | awk "$(tail -n +3 $0)"	# TODO: reverse order of arguments
exit $?

{
	lines[NR] = $0;
}

END {
	for (i = NR; i > 0; i--) {
		print lines[i]
	}
}
