// help_file.c
// Contains the help file efun.
// The original author didn't put a header on it.
// Mobydick added this one on 2-18-93.
// We have a strong suspicion that this isn't called anymore.
// Erase it at your own risk... ;)

#include <daemons.h>

string
help_file(mixed arg)
{
	string filename;

	if (objectp(arg)) {
		filename = "/help" + base_name(arg);
	} else if (stringp(arg)) {
		filename = "/help" + (string)COMMAND_D->where(arg);
	} else {
		return 0;
	}
	if (file_exists(filename)) {
		return filename;
	} else {
		return 0;
	}
}
