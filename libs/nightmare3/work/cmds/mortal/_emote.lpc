/*
// Author unknown (??)
// Help added by Brian (1/28/92)
*/

#include <std.h>

inherit DAEMON;

#define SZ 75

int
cmd_emote(string str) {
    string first,tail,insert;

    if(this_player()->query_ghost()) {
        notify_fail("A ghost has no feelings.\n");
        return 0;
    }
    if(!str) {
      write("You look emotional.");
      say(this_player()->query_cap_name() + " looks emotional.");
      return 1;
    }
    if (sscanf(str," %s",tail)==1) insert = "";
    else if (sscanf(str,"'%s",tail) == 1) insert = "";
    else insert = " ";
    if((int)this_player()->query_mp() <0 && (int)this_player()->query_level() < 20) {
      write("You are low on magic points.");
        return 1;
    }
    if((int)this_player()->query_level() < 20) this_player()->add_mp(-7);
    write(sprintf("%-="+SZ+"s",
		"You emote: "+this_player()->query_cap_name()+insert+str));
    say(sprintf("%-="+SZ+"s",
           this_player()->query_cap_name() + insert + str));
    return 1;
}

int
help() {
  write("Syntax: <emote [string]>\n"+
	"Whatever string you type in will be given to every one in the room\n"+
	"with you following your name.  Thus the command:\n"+
        "emote sits down and relaxes.      will do:\n"+
        "Brian sits down and relaxes.\n"+
        "(With your name substituted for Brian)\n");
    write("Cost for players under level 20: 7 mp\n"+
	"For immortals and high mortals: free\n");

  write("See also: say, whisper, yell\n");
  return 1;
}
/* EOF */
