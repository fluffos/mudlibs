//#pragma save_binary
// _dump.c
// A front-end command to the dumpallobj() efun.
// Will produce a list of all loaded objects.
// The output is stored in the file /OBJ_DUMP. Tends to be large.
// Original author unknown, although Buddha is probable.
// Date unknown, perhaps September 1992.
// This header added by Mobydick, 11-9-92

#include <mudlib.h>

inherit DAEMON ;

int cmd_dump() { dumpallobj(); return 1; }

int help() {
	write (
"The dump command calls the dumpallobj efun, which places a list of all\n"+
"loaded objects into the root directory. See the man page on the dumpallobj\n"+
"efun for more details.\n") ;
	return 1 ;
}
