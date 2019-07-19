if [ -n "$*" ]; then
	for i in $*; do
		printf '%s=%s\n' "${i}" "${$i}"
	done
else
	env
fi
