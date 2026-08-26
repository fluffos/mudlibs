/*
 * du - Disk Usage
 * shows usage (in K) in all directories below a specified point
 * without args, the default is the current dir
 *
 * Written by: Gunn @ TMI (01/22/92)
 * Rewritten by: Val @ TMI (Aug 94)
 */

#include <mudlib.h>

inherit DAEMON ;

#define MAX_RECURSE 4

private int
du_show(string path, int level)
{
    mixed *dir;
    int   i, size;

    if (level++ > MAX_RECURSE) return 0;

    dir = get_dir(path, -1);
    if (!dir) {
	write("Cannot access: " + path + "\n");
	return 1;
    }

    /* Size = 1 because the directory reserves some space too */
    for (i = 0, size = 1; i < sizeof(dir); i++)
    {
        if (dir[i][1] == -2)
            size += du_show(path + dir[i][0] + "/", level);
        else
            size += (dir[i][1] + 1023) >> 10;
    }
    write(size + "\t" + implode(explode(path, "/")[0..<2], "/") + "\n");
    return size;
}

int cmd_du(string path)
{
    seteuid(getuid(previous_object()));
    if (path) {
	path = resolv_path((string)this_player()->query("cwd"),path);
    } else {
	path = (string)this_player()->query("cwd");
    }
    du_show(path + "/", 0);
    return 1;
}

string help()
{
    return("du - Disk Usage\n\n"+
           " Syntax: du [path]\n\n"+
   " 'du' recursively scans directories, starting from the specified\n"+
	  " path. File sizes are added up, and a total 'K' amount for each\n" +
	  " directory is displayed. If no path is supplied, the current\n" +
	  " directory is used.\n\n");
}
