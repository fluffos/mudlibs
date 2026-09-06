// --Val (94-12)
// Reduce the full path to path including ~ if possible.
// Adds / to the beginning if it is missing.

varargs string
tilde_path( string str, string user )
{
    string name;

    if (!stringp(str)) return 0;

    if (str[0] != '/') str = "/" + str;

    if (sscanf(str, PATH_USER "%s/%s", name, str) == 2) {
	return sprintf("~%s/%s", (name==user) ? "" : name, str);
    }
    return str;
}
