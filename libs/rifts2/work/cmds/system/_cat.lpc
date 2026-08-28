/* $Header: /mud/tkv/bin/system/RCS/_cat.c,v 1.2 1995/06/30 21:23:32 mudriver Exp $

 * $Log: _cat.c,v $

 * Revision 1.2  1995/06/30  21:23:32  mudriver

 * Formatted and added RCS info

 *

 * Ported to DarkeMud by Zortek

 */

#include <std.h>



inherit         DAEMON;



int             help();

int             cmd_cat(string file);



int

cmd_cat(string file)

{

    seteuid(getuid(previous_object()));

    if (!file) {

	help();

	return 1;

    } else {

	file = resolv_path(this_player()->get_path(), file);

	if (!cat(file))

	    write(file + ": no such file\n");

	return 1;

    }

}



int 

help()

{

    write(@TEXT

Syntax:<cat[filename] >



Writes the contents of the filename given to standard output.  If the

file is over a system - defined maximum(usually 80 lines), then the

message ***** TRUNCATED ***** will appear.In this case, you may wish

to use the more command instead.



See also:

head, tail, more, less.

TEXT

);

    return 1;

}

