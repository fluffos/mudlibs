/*
// File     :  /cmds/ambassador/_law.c
// Comment  :  Lists mortal law
// 94-09-04 :  Pallando @ Nightmare wrote it
*/
#include <std.h>

#define COUNCIL_CHAMBER "/domains/standard/council"

inherit DAEMON;

int cmd_law( string title )
{
    return COUNCIL_CHAMBER-> cmd_law( title );
}

void help()
{
    message( "help",
	"Syntax: law [<title>]\n"
	"If no title is given, this command lists the titles of all laws.\n"
	"If a title is given, it displays the law with that title.\n"
	, this_player()
    );
}
