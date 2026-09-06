varargs string
implode(string *x, string a, string b)
{
    int size;
    mixed tmp;
    string s;
    if (!b) {
	return efun::implode(x, a);
    } else {
	size = sizeof(x);

	if (size == 0 || size == 1) {
	    return efun::implode(x, a);
	} else if (size == 2) {
	    return efun::implode(x, b);
	} else {
	    tmp = x[<1];

	    if (!stringp(tmp)) {
		return implode(x, a);
	    } else {
		// Kludge, for arrays that aren't quite ok... :-/
		x[<1] = 0;
		s = sprintf("%s%s%s", efun::implode(x, a), b, tmp);
		x[<1] = tmp;

		return s;
	    }
	}
    }
}
