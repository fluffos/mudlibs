/*
  /sys/filepath.h

  Fix function for getting a correct filepath.

*/

#ifndef FPATH_DEF
#define FPATH_DEF

#define FPATH_FILENAME "/sys/global/filepath"

/*
 * Gives a composite path from a default and a given pathname
 *
 * If name starts with '/' then path is ignored.
 * 
 * Example: path = "/d/Genesis/wiz", name = "below/eastend.lpc"
 *          => "/d/Genesis/wiz/below/eastend.lpc"
 */
#define FPATH(path, name) ((string)FPATH_FILENAME->fix_path(path, name))

/*
 * Gives a full path from a tildepath, with '~/' interpreted as the homedir
 * of the wizard 'name'
 */
#define TPATH(name, tilde) ((string)FPATH_FILENAME->get_tilde_path(name,tilde))

/*
 * Combines FPATH and TPATH
 *
 * this_player() is assumed to be the wizard '~/'
 */
#define FTPATH(p, n) FPATH(p, TPATH(this_player()->query_real_name(), n))

/*
 * Reduces a path to its tilde counterpart
 */
#define RPATH(path) ((string)FPATH_FILENAME->reduce_to_tilde_path(path))

#endif
