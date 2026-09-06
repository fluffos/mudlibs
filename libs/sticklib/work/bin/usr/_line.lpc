// Display a specific line of a file plus a couple of
// lines before and after.
// Haw 070497

#include <cmd.h>

status
line_cmd(string s)
{
    int i, l, h;
    string f, *lines, tmp;

    if(!CHECK)
	return 0;
    if(!s || sscanf(s, "%d %s", l, f) < 2)
	return notify_fail("Usage: line <linenum> <file>\n"),0;

    f = (string)this_player()->absolute_path(f);

    if(l < 1 || l > file_lines(f))
	return notify_fail("Invalid line number.\n"),0;
    if((l -= 3) < 1)
	l = 1;
    if(!(tmp = read_file(f, l, 7)))
	return notify_fail("Read failed.\n"),0;

    h = sizeof(lines = explode(tmp, "\n"));
    tmp = "\n";
    i = 0;

    while(i < h) {
	tmp = sprintf("%s%d\t%s\n", tmp, i+l, lines[i]);
	i++;
    }
    this_player()->tell_me(tmp);

    return 1;
}
