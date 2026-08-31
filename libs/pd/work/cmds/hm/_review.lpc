//	/bin/high_mortal/_review.c
//	from the Nightmare mudlib
//	created by Sulam 21 december 1991

#include <std.h>

inherit DAEMON;

int
cmd_review()
{
	write("Your messages are:\n");
        write("TITLE:   " + (string) this_player()->query_title() + "");
	write("MIN:     " + (string) this_player()->query_min() + "");
	write("MOUT:    " + (string) this_player()->query_mout() + "");
  if (wizardp(this_player())) {
	write("MMIN:    " + (string) this_player()->query_mmin() + "");
	write("MMOUT:   " + (string) this_player()->query_mmout() + "");
        write("MHOME:   " + (string) this_player()->query_mhome() + "");
	write("MDEST:   " + (string) this_player()->query_mdest() + "");
	write("MCLONE:  " + (string) this_player()->query_mclone() + "");
	write("MVIS:    " + (string) this_player()->query_mvis() + "");
	write("MINVIS:  " + (string) this_player()->query_minvis() + "");
  }
        write("See 'help title' and 'help message' for more information.");
	return 1;
}

int
help() {
  write("Syntax: review\n\n"+
    "This command shows you your current title and movement messages.\n\n"+
    "See also: title, message");
  return 1;
}
/* EOF */
