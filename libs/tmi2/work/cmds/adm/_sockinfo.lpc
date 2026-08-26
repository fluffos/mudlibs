// sockinfo.c
// Written by Truilkan@TMI, 11-8-92
// Dumps a bunch of information about the sockets of the host machine onto
// the screen.
// Mobydick added this header, 11-9-92. He doesn't know what the dumped
// numbers mean.

#include <mudlib.h>

inherit DAEMON ;

int cmd_sockinfo() { write(dump_socket_status()); return 1; }

string help() {
	return (
"The sockinfo command will tell you what sockets are loaded and what they\n"+
"are currently being used for. It calls the efun dump_socket_status. See\n"+
"the man page on that efun for more information.\n") ;
}
