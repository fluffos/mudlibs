#include <cmd.h>

nomask int
convert_cmd(string str)
{
    string file, old, new;
    string tmp;
    int amount;
    string *x;

    if (!CHECK) return 0;
    if (!str || sscanf(str, "%s %s=%s", file, old, new) < 3)
	return notify_fail("Usage: convert <file> <old>=<new>\n"), 0;
    file = (string) this_player()->absolute_path(file, 1);
    if (file[0] != '/') file = "/" + file;
    tmp = read_file(file);
    x = explode(tmp, old);
    amount = sizeof(x) - 1;
    tmp = implode(x, new);
    rm(file);
    write_file(file, tmp);
    this_player()->tell_me("Ok. "+amount+" occasions replaced.");
    return 1;
}
