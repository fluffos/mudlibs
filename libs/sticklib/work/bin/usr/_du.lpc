#include <cmd.h>
#define LIB_RESOLVE_PATH "/std/lib/resolve_path"
inherit LIB_RESOLVE_PATH;

/*
// 'du' - print disk usage
// By Val (tero.pelander@utu.fi)
// Amylaar version
*/

private int du_show(string path);

nomask int
du_cmd(string path)
{
    path = resolve_path(path ? path : ".", this_player());

    if (path[-1..-1] != "/")
	path += "/";

    if (file_size(path) != -2) {
	write("No such directory.\n");
	return 1;
    }

    /* Weed out some unwanted "too long evaluation" cases. */
    if (sizeof(explode(path, "/")) < 2 ) {
	write("Start at deeper in the structure. (Min 2 directories deep.)\n");
	return 1;
    }

    du_show(path);
    return 1;
}

private int
du_show(string path)
{
    int     *dir;
    int   i, size;

    dir = get_dir(path, 3);
    if (!dir) return 1;

    /* Size = 1 because the directory reserves some space too */
    for (i = 1, size = 1; i < sizeof(dir); i += 2)
    {
	if (dir[i] == -2)
	    size += du_show(path + dir[i-1] + "/");
	else
	    size += (dir[i] + 1023) >> 10;
    }
    write(size + "\t" + path[0..-2] + "\n");
    return size;
}
