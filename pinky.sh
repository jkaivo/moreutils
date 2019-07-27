for i in "$@"; do
	who | grep -F "$i"
done
