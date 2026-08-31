//   written by Plura@Nightmare in January 93
#include <std.h>
#include <daemons.h>

inherit DAEMON;

int help();

int cmd_head(string str) {
    string *lines;
    string file;
    int n;

    seteuid(getuid(previous_object()));

    if(!str) { help(); return 1; }
    file = resolv_path(this_player()->get_path(), str);
    if(!file) return notify_fail("No such file: "+file+"\n");
    else if(!(str = read_file(file)))
	return notify_fail("Empty file: "+file+"\n");
    if((n = sizeof(lines = explode(str, "\n"))) > 22) n = 23;
    str = implode(lines[0..n-1], "\n");
    message("system", str, this_player());
    IMSTAT_D->add_stat(this_player()->query_name(), "head", time());

    return 1;
}


int help()
{
    write( @EndText
Syntax: head <file>
Effect: lists the first 20 lines of the file <file>
See also: tail, cat, more, less
EndText
    );
    return 1;
}
