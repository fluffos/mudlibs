/*
// This file is part of the TMI distribution mudlib.
// Please include this header if you use the code here.
// Written by Sulam(12-13-91)
// Help?? added by Brian on that most wonderful of days (1/28/92)
*/

#include <mudlib.h>

inherit DAEMON;

int
cmd_save(string str) {

    object link ;

    this_player()->save_me();
    link = this_player()->query_link() ;
    if (link) {
	link->save_data() ;
    }
    write(this_player()->query("cap_name")+" is now saved.\n");
    return 1;
}

int
help() {
  write("Command: save\nSyntax: save\n"+
        "This command saves the present status of your character to disk.\n"+
        "This is important as it is this file that will be used to set\n"+
        "your character back up if the mud should crash.  Your character is\n"+
        "automatically saved if you quit.\n");
  return 1;
}
/* EOF */
