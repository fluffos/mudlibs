//      /bin/dev/_log.c
//      from the Nightmare Mudlib
//      tails a given log
//      created by Brian@TMI 920128

#include <std.h>
#include <dirs.h>

inherit DAEMON;

int cmd_tlog(string file) {
    int size, tmp;
    if (!file) 
	return notify_fail("Correct syntax: <tlog [log file]>\n");
    else file = DIR_LOGS+"/"+file;
    size = file_length(file);
    if (!tmp) tmp=30;
    size = size-tmp;
    if (size < 1) size=1;
    if(!file_exists(file)) write ("No such log file: "+file+"\n");
    else write(read_file(file, size));
    return 1;
}

void help() {
    write("Syntax: <log [log file]>\n\n"
      "Tails the log file named (i.e. a file in the mud log directory).\n\n"
      "See also:\nelog, replog\n"
    );
}
