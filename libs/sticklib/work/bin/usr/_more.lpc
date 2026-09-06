#include <cmd.h>

status
more_cmd(string file, object me)
{
    string buffer;
    string *files;

    if (!CHECK) return 0;

    if (!me) me = this_player();

    if (!file) return notify_fail("Usage: more <file>.\n"), 0;

    file = (string) me->absolute_path(file, 1);
    if (!file || !sizeof(files = get_dir(file))) {
	me->tell_me("No such file (or no access to it).");
	return 1;
    }
    file = sprintf("/%s/%s", efun::implode(explode(file, "/")[0..<2], "/"),
      files[0]);
    me->more(file);
    return 1;
}
