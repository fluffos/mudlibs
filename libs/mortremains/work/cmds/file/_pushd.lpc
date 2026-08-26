/*
// file: _pushd.c
// author: Truilkan@TMI
// last modified: 1992/03/08
*/

#include <config.h>
#include <mudlib.h>

inherit DAEMON ;

int
cmd_pushd(string str) {
	object pobj;

	if (!(pobj = previous_object()))
		return 0;
	
	return (int)pobj->pushd(str);
}

string
help() {
  return("Command: pushd\nSyntax: pushd <directory>\n"+
	"Pushd works just like cd except that it also pushes the current\n" +
	"directory onto a stack so that it can be returned to with the popd\n" +
	"command.\n");
}
