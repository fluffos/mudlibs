/*
 * tilde_path
 * Change path name to contain the tilde (~) mark if it can be shortened.
 * Optional 'player' can be string or object.
 */


#ifndef _CONFIG_H
#include <config.h>
#endif

#define REAL_NAME(pl)	((string)pl->query_real_name())

nomask public varargs string tilde_path(string path, mixed player) {
    if (sscanf(path, PATH_USER "%s", path)) {
	string base;

	if (objectp(player)) player = REAL_NAME(player);
	if (sscanf(path, "%s/%s", base, path)) {
	    path = "/" + path;
	} else {
	    path = "";
	}
	if (base == player) return "~" + path;
	return sprintf("~%s%s", base, path);
    }
    return path;
}
