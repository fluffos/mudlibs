// -*- LPC -*-
// path_utils.c:  Routines for working with file paths
//
// Copyright (C) 1996 Tim McIntosh (tmcintos@dm.imaginary.com)
//
// This program is part of the OpenLib Mudlib distribution; it
// is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2 of the License,
// or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// If you acquired this program as part of the OpenLib Mudlib
// distribution, you should have received a copy of the GNU
// General Public License in the file /doc/GPL; if not,
// write to the Free Software Foundation, Inc., 675 Mass Ave,
// Cambridge, MA 02139, USA.
//
#include <mudlib.h>
#include <dirs.h>

// Get the filename of an object without the object number (with no .c)

string
base_name(object ob)
{
  string str = file_name(ob);
  int idx = strsrch(str, '#');

  if(idx == -1) return str;
  else return str[0..idx-1];
}

// Returns the path to the home directory of a user with username 'name'

string
user_cwd(string name)
{
  if(!name) return "";
  return sprintf(USER_DIR "/%c/%s", name[0], name);
}

// Same as above but tacks on a trailing /

string user_path(string name)
{
  return (user_cwd(name) + "/");
}

/*
 * Based on resolve_path() from the TMI-2 mudlib:
 *   Thanks to Huthar for resolve_path.
 *   Rewrite by Symmetry 5/4/95
 *
 * 09/16/95  Tim McIntosh:  Fixed this so it actually works right :)
 */

string absolute_path(string current, string relative) {
  int i, j, size;
  string *tmp;
    
  switch(relative) {
  case 0: 
  case ".":
    return current;
  case "~":
    return user_cwd(this_player()->query_name());
  default: {
    if (relative[0..1] == "~/") {
      relative = user_path(this_player()->query_name()) + relative[2..];
    } else {
      switch(relative[0]) {
      case '~': {
	i = strsrch(relative, '/');
	if (i < 0)
	  relative = user_path(relative[1..]);
	else
	  relative = user_path(relative[1..i-1]) + relative[i..];
	break;
      }
      case '/':
	break;
      default:
	relative = current + "/" + relative;
      }
    }
    
    if (relative[<1] != '/') relative += "/";

    /*  Figure out .. and .'s in the path  */
    size = sizeof(tmp = regexp(explode(relative, "/"), "."));
    
    i = j = 0;
    
    while (i < size) {
      switch(tmp[i]) {
      case "..":
	if (j){
	  while (j-- && !tmp[j]);
	  if (j >= 0) tmp[j] = 0;
	  else j++;
	}
      case ".":
	tmp[i++] = 0;
	break;
      default:
	j = ++i;
	break;
      }
    }
    return "/" + implode(tmp, "/");
  }  /* default: */
  }  /* switch(relative) */
}

/*
 * glob() written by Tim 2/13/96
 *
 * Analogous to get_dir() but allows wildcards in all levels of the path.
 * Returns an array of all paths matching 'pattern' at each level of the
 * directory tree.  All paths should be absolute.
 *
 * 'root'    the starting directory (no wildcards in this part).
 * 'pattern' is an array with the glob pattern to match at each level of the
 *           directory tree. i.e. pattern[0] is the pattern to match at the
 *           starting level.  Probaby get this by explode(somepath, "/");
 *           where the full path was (root + somepath)
 */

string*
glob(string root, string* pattern)
{
  string* matches = get_dir(sprintf("%s/%s", root, pattern[0]));

  if(!matches || !sizeof(matches)) return ({});

  if(sizeof(pattern) == 1) {
    for(int i = 0; i < sizeof(matches); i++)
      matches[i] = sprintf("%s/%s", root, matches[i]);
    return matches;
  } else {
    string* ret = ({});

    foreach(string file in matches)
      ret += glob(sprintf("%s/%s", root, file), pattern[1..]);
    return ret;
  }
}
