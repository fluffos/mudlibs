// An "addendum" to cd. Completes a directory name.
// 230498 Haw

status
chd_cmd(string str)
{
    string c, p, *d;
    int i, j, l, n;

    if(!str) {
	command("cd", this_player());
	return 1;
    }

    p = (string)this_player()->absolute_path(str);
    if(file_size(p) == -1) {
	i = sizeof(p);
	while(p[--i] != '/');
	c = p[i+1..];
	l = sizeof(c);
	p = p[0..i];
	d = get_dir(p);
	n = sizeof(d);
	j = 0;
	while(j < n) {
	    if(d[j][0..l-1] == c && file_size(sprintf("%s%s", p, d[j])) == -2)
		break;
	    j++;
	}
	if(j < n) {
	    str = sprintf("%s%s", p, d[j]);
	    this_player()->tell_me(sprintf("Completing: cd %s", str));
	}
    }

    command(sprintf("cd %s", str), this_player());
    return 1;
}
