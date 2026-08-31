/*
// This file is part of the TMI mudlib distribution.
// Please include this header if you use this code.
// Written by Sulam(12-16-91)
// Changed cause new driver doesnt have a tail() efun
// -Nightshade
*/

#include <daemons.h>
#include <std.h>
inherit DAEMON;

int cmd_tail(string file) {
    int size, tmp;
    string tmp2;

    if(sscanf(file, "%s (%d)", tmp2, tmp)==2) file=tmp2;
    seteuid(getuid(previous_object()));
    if (!file) {
	notify_fail("usage: tail <file>\n");
	return 0;
    }
    file = resolv_path(this_player()->get_path(), file);
    switch(file_size(file)) {
    case -2:
	notify_fail("tail: "+file+": is a directory\n");
	return 0;
    case -1:
	notify_fail("tail: "+file+": no such file\n");
	return 0;
    }
    size = file_length(file);
    if(!tmp) tmp=20;
    size = size - tmp;
    if(size < 1)
	size = 1;
    write(read_file(file, size));
    IMSTAT_D->add_stat(this_player()->query_name(), "tail", time());
    return 1;
}

int help()
{
    write( @EndText
Syntax: tail <file> (#lines)
Effect: lists the last few lines of the file <file> If optional #lines
 is filled, it will display the last #lines of a file.

See man: tail
See also: head, cat, more, less
EndText
    );
    return 1;
}

