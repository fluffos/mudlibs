//	/bin/high_mortal/_review.c
//	from the Nightmare mudlib
//	created by Sulam 21 december 1991

#include <std.h>

inherit DAEMON;

int
cmd_review()
{
	write("Your messages are:\n");
        write("TITLE:   " + (string) this_player()->query_title() + "\n");
	write("MIN:     " + (string) this_player()->query_min() + "\n");
	write("MOUT:    " + (string) this_player()->query_mout() + "\n");
	write("MMIN:    " + (string) this_player()->query_mmin() + "\n");
	write("MMOUT:   " + (string) this_player()->query_mmout() + "\n");
        write("MHOME:   " + (string) this_player()->query_mhome() + "\n");
	write("MDEST:   " + (string) this_player()->query_mdest() + "\n");
	write("MCLONE:  " + (string) this_player()->query_mclone() + "\n");
	write("MVIS:    " + (string) this_player()->query_mvis() + "\n");
	write("MINVIS:  " + (string) this_player()->query_minvis() + "\n");
	write(
"\n  You can change your moving messages with the set command.\n");
	write( "  For more information 'help set'.\n");
	return 1;
}

int
help() {
  write("Command: review\nSyntax: review\n"+
        "This command shows you what your basic wizard messages are\n"+
        "currently set to.  In order to change them you need to use\n"+
        "the set command.\n");
  return 1;
}
/* EOF */
