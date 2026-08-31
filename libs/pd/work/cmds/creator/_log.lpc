//      /bin/dev/_log.c
//      from the Nightmare Mudlib
//      tails a given log
//      created by Brian@TMI 920128

#include <std.h>
#include <dirs.h>

inherit DAEMON;

int cmd_log(string str) {
    if (!str) 
	return notify_fail("Correct syntax: <log [log file]>\n");
    else str = DIR_LOGS+"/"+str;
    write(str+":\n");
    if(!file_exists(str)) write ("No such log file: "+str+"\n");
    else this_player()->more(str);
    return 1;
}

void help() {
    write("Syntax: <log [log file]>\n\n"
      "Tails the log file named (i.e. a file in the mud log directory).\n\n"
      "See also:\nelog, replog\n"
    );
}
