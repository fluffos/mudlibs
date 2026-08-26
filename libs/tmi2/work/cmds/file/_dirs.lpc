/*
// file: _pushd.c
// author: Zak@{TMI-2, icosahedron, underdark}
// last modified: 930216
// made help text consistent with others (loknar 3/11/93)
*/

#include <config.h>
#include <mudlib.h>

inherit DAEMON ;

int cmd_dirs()
{
    object pobj;
    mixed *stak;

    if (!(pobj = previous_object()))
	return 0;
	
    stak = ({ pobj->query("cwd") }) + pobj->dirs();
    printf("%s\n", implode(stak, " "));
    return 1;
} // cmd_dirs


string help()
{
  return( @ENDHELP
Usage: dirs

This command displays the directory stack as used by pushd and popd.
The current directory is always displayed first.

See also: pushd, popd
ENDHELP
);
}

