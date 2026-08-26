/*
// Help added by Brian (1/28/92)
// Revised by Buddha@TMI (8/1/92)
*/

#include <mudlib.h>

inherit DAEMON ;

int cmd_emote(string str) {
    string first,tail,insert;

    if(!str) {
      write("You look emotional.\n");
      say(this_player()->query("cap_name")+" looks emotional.\n");
      return 1;
    }
    if (!wizardp(previous_object())) first = "-> ";
    else first = "";
    if (sscanf(str," %s",tail)==1) insert = "";
    else if (sscanf(str,"'%s",tail) == 1) insert = "";
    else insert = " ";
    write(iwrap("You emote: " + first + this_player()->query("cap_name") +
	 insert + str));
    say(iwrap(first + this_player()->query("cap_name") + insert + str));
    return 1;
}

string help() {
  return("Syntax: emote <string>\n\n"+
        "This broadcasts what you type to the room in the\n"+
        "form of: <yourname>+\" \"+string.  Thus the command:\n"+
        "emote sits down and relaxes.\n"+
        "will broadcast:\n"+
        "Brian sits down and relaxes.\n"+
        "(With your name substituted for Brian)\n");
}
/* EOF */
