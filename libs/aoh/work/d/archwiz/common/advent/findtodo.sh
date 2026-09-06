find . -type f \! -name "TODO" \! -name "findtodo.sh" \! -name "*~" -exec grep TODO {} /dev/null \;
