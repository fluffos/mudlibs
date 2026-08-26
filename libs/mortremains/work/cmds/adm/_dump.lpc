// _dump.c
// A front-end command to the dumpallobj() efun.
// Will produce a list of all loaded objects.
// The output is stored in the file /OBJ_DUMP. Tends to be large.
// Original author unknown, although Buddha is probable.
// Date unknown, perhaps September 1992.
// This header added by Mobydick, 11-9-92

#include <config.h>
#include <mudlib.h>

inherit DAEMON ;

int cmd_dump(string path) {
    if (path && path != "") {
        path = resolv_path("cwd", path);
	if (MASTER_OB->valid_write(path, geteuid(previous_object()), "dump")) {
	    if (file_size(path) == -2)
		path += "/OBJ_DUMP";
	    dumpallobj(path);
	} else {
	    notify_fail(sprintf("dump: can't write to \n", path));
	    return 0;
	}
    } else
	dumpallobj();
    return 1;
}

string help() {
    write(
"Syntax: dump [destination_path]\n\n"
"The dump command calls the dumpallobj efun, which places a list of all\n"
"loaded objects into the root directory, by default.\n\n"
"See the dumpallobj() efun man page for more details.");
}
