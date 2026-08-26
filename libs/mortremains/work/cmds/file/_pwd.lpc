/*
// This file is part of the TMI Mudlib distribution.
// If you use this code without this header, we'll hunt you down and kill you.
// Written by Sulam(12-21-91)
// Just for tradition this files help was added by me too (Brian)
// and the date was...You guessed it! (1/28/92)
// 07-05-93 Added test for null cwf.  Grendel@TMI-2
*/

#include <mudlib.h>

inherit DAEMON ;

int
cmd_pwd()
{
	string file;

	write("Dir  :"+(string)this_player()->query("cwd")+"\n");
	file=(string)this_player()->query("cwf");
	if(!file)
		write("File :None\n");
	else
		write("File :"+file+"\n");
	return 1;
}

string
help() {
  return("Command: pwd\nSyntax: pwd\n"+
        "This command returns the directory that you are currently\n"+
	"working in, and the current default file.\n") ;
}
