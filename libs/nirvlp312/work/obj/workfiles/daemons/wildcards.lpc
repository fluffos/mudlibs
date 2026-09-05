/*
 *      File:                   /obj/daemons/wildcards.c
 *      Function:               Return file or files responding to
 *                              wildcards specified.
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2005 Earwax/David Halek
 *                                      All Rights Reserved.
 *      Source:                 10/27/2005
 *      Notes:                  (mixed)WILDCARDS->get_files()
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#pragma weak_types

/* Prototype declarations */
string get_path(string path);

/* Global Variables */
mixed *Info;

/*  
 * Function name:  get_files()
 * Description:    Returns an array of files matching wildcard criteria.
 * Arguments:      String dir, or filename with or without wildcards
 *                   string path - path/mask to return
 *                   Flags: status ffname, fsilent
 *                   1: Return just filenames (otherwise full path)
 *                   1: Silent flag - no error messages displayed.
 * Returns:        Array of files matching specified wildcards.
 *                   0 if file or dir does not exist.
 */

varargs string *get_files(string path, status ffname, status fsilent)
{
  string dir, *t;
  int i, j;
  
  if (!path) path = (string)this_player()->query_pwd();
	path = resolve_path(path);
	i = strlen(path) -1;
  if (path[i] == '/') path = path[0..i-1];
    
  if (path && path != "/")
  {
    if (file_size(path) >= 0)
    { 
      t = explode(path, "/");
      dir = "/"+implode(t[0..sizeof(t) - 2], "/") + "/";
    }
    else
    { 
      if (file_size(path) == -2 ||
         (!text_contains(path, "*") && !text_contains(path, "?") == -1))
      {
	      if ( path[strlen(path)-1] != '/')
	        path += "/";
	      dir = path;
      }
      else
      {
	      t = explode(path, "/");
	      dir = "/" + implode(t[0..sizeof(t)-2], "/") + "/";
	    }
    }
  }
  else
  {
    dir = "/";
  }
  
  Info = get_dir(path);

  if (!Info)
  {
    if (!fsilent)
      write("Invalid directory: "+dir+"\n");
    return 0;
  }

  t = ({ });
  j = sizeof(Info);
  for (i = 0; i < j; i ++)
  {
    if (Info[i] != ".." || Info[i] != ".")
    {
      if (dir == "//") dir = "/";
      if (!text_contains(Info[i], "..") && Info[i][strlen(Info[i])-1] != '.')
        if (file_size(dir+Info[i]) == -2 && Info[i][strlen(Info[i])-1] != '/') 
          ({ Info[i] += "/" });
      t += (ffname ? ({ Info[i] }) : ({ dir + Info[i] }));
    }
  }

  return t;
}
 
