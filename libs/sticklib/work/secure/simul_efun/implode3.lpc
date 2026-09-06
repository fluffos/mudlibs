// Fixed a bit 16-jul-96. -+ Doomdark +-

varargs string
implode3(string *x, string a, string b)
{
    int i, last;
    mixed tmp;
    string s;
    i = sizeof(x);
    while (--i >= 0) {
	if (stringp(x[i])) {
	    last = i;
	    break;
	}
    }
    // No single string?
    if (i < 0)
	return "";
    while (--i >= 0) {
	if (stringp(x[i])) {
	    break;
	}
    }
    // Just one string?
    if (i < 0)
	return x[last];
    // Ok. So we have at least 2 strings... piece of cake!
    tmp = x[last];
    x[last] = 0;
    s = implode(x, a);
    x[last] = tmp;
    return sprintf("%s%s%s", s, b, tmp);
}
