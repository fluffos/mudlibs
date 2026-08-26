/*
// This file is part of the TMI mudlib distribution.
// Please include this header if you use this code.
// Written by Sulam(12-16-91)
*/

#include <config.h>
#include <mudlib.h>

inherit DAEMON ;

int
cmd_tail(string file) {
    seteuid(getuid(previous_object()));
    if (!file) {
      notify_fail("usage: tail <file>\n");
      return 0;
    }
    file = resolv_path(this_player()->query("cwd"), file);
    switch(file_size(file)) {
	case -2:
	    notify_fail("tail: "+file+": directory\n");
	    return 0;
	case -1:
	    notify_fail("tail: "+file+": no such file\n");
	    return 0;
    }
    tail(file);
    return 1;
}

string help() {
	return ("Usage: tail <filename>\n\n"+
"The tail command lets you view the last 20 lines of the given file. This\n"+
"command is good for looking at the end of large files with new information\n"+
"added to the end, such as error log files.\n") ;
}
/* EOF */
