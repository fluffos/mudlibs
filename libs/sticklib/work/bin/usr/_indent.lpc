#include <cmd.h>

status
indent_cmd(string file, object me)
{
    string buffer;

    if (!CHECK) return 0;

    if (!me) me = this_player();

    if (!file) return notify_fail("Usage: indent <file>.\n"), 0;

    file = (string) me->absolute_path(file, 0);
    if (!file || file_size(file) < 1) {
	me->tell_me("No such file (or no access to it).");
	return 1;
    }

    if( !(buffer = read_file(file)) || !write_file(file + "_IBackup",  buffer) )
    {
	me->tell_me(
	  "Fatal: Cannot create backup file (too big file, probably).\n\
(Use ed instead to indent it)");
	return 1;
    }

    if(!cindent(file))
    {
	me->tell_me("Can not indeant '" + file + "'.");
	return 1;
    }
    me->tell_me("'"+file+"' indented.");
    return 1;
}
