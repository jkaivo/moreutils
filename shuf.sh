exec awk "$(tail -n +2 $0)" "$@"

{
	lines[NR] = $0;
	printed[NR] = 0;
}

END {
	nprinted = 0;
	while (nprinted < NR) {
		line = int(rand() * NR);
		if (!printed[line]) {
			print lines[line];
			printed[line] = 1;
			nprinted++;
		}
	}
}
