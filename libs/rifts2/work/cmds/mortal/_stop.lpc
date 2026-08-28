#include <std.h>

inherit DAEMON;

int cmd_stop(string str) {
    object spell;

    if(str == "hunting"){
        this_player()->stop_hunting();
        write("No longer hunting.");
        return 1;
    }
    if(str == "casting"){
        if(spell = this_player()->query_casting()){
            message("info", "%^BOLD%^%^GREEN%^You stop casting your spell.%^RESET%^", TP);
            spell->remove();
            TP->set_casting(0);
            return 1;
        }
        message("info", "%^BOLD%^%^GREEN%^You are not casting a spell.%^RESET%^", TP);
        return 1;
    }
    return 0;
}

int help() {
  message("help",
    "This command is used to either clear your hunting list, or to stop casting a spell.  If used to stop hunting, you will not auto attack any monsters or players who have attacked you, and that are not currently in the same room as you.  If used to stop casting, it does just that, it ends the casting process of the spell being cast.\n"
"Syntax:\n"
"        stop casting\n"
"        stop hunting\n",
  this_player());
  return 1;
}

