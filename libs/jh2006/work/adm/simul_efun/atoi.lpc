// atoi.c

int atoi(string str)
{
	int v;

	if (!stringp(str) || !sscanf(str, "%d", v))
		return 0;
	return v;
}

string strip(string str)
{
	string prefix, suffix;

	if (!stringp(str))
		return str;
	while (sscanf(str, "%s[%*sm%s", prefix, suffix) == 3)
		str = prefix + suffix;
	return str;
}
