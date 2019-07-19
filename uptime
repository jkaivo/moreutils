printf ' %s' "$(date +%T)"
printf ' up since %s,' "$(who -b | sed -e s/^.*boot[[:space:]]//)"
printf ' %2d users' $(who | wc -l)
# load average
printf '\n'
