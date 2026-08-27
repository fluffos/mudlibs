/*  -*- LPC -*-  */
// du.c:  Displays disk usage in Kilobytes for a given directory or file.
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
// Created by Tim 18 Jul 1996
//

#include <cmdline.h>

int du(string p, int silent);

int
main(string* argv1, string* argv2)
{
  string path;
  int size, opts = flag("s");

  if( !sizeof(argv2) )
    path = this_player()->query_cwd();
  else
    path = argv2[0];

  path = RESOLVE_PATH(path);

  switch( size = file_size(path) )
  {
  case -1:
    return notify_fail("du: No such file or directory.\n");
  case -2:
    if( path[<1] != '/' )
      path += "/";
    size = du(path, opts);
    if( !opts )
      return 1;
    break;
  }    

  message("system", sprintf("%-10i %s\n", size/1024, path), this_player());
  return 1;
}

// PRE: p is a directory, last char is '/'
// POST: returns number of bytes used by file hierarchy rooted at p
int
du(string p, int silent)
{
  mixed* dir_stats = get_dir(p, -1);
  mixed* directories = filter(dir_stats, (: $1[1] < 0 :));
  int ret;

  foreach(mixed* file in dir_stats - directories)
    ret += file[1];

  foreach(mixed* dir in directories)
    ret += du(p + dir[0] + "/", silent);

  if( !silent )
    message("system", sprintf("%-10i %s\n", ret/1024, p), this_player());

  return ret;
}
