//    Stasis object.
//    By Nightshade.
//    Modded by Amarael to lock terminal.
 
#include <std.h>
inherit OBJECT;

string keyp;

void create() {
   ::create();
     set_property("no steal", 1);
     set_name("lock");
     set_heart_beat(1);
     set_short("");
     set_long("!ERROR! WTF!");
     set_weight(0);
     set_value(0);
     set_id(({"player_lock"}));
}

void lockme(string tmp) {
     keyp = tmp;
     write("\n\n\nTerminal Locked.\nPassword:");
     add_action("no_cmds", "", 1);
}

int no_cmds(string str) {
  string verb;
  verb = query_verb();
  if(verb == keyp) {
    write("\n%^YELLOW%^Terminal Unlocked%^RESET%^\n");
    this_object()->remove();
    return 1;
    }
  else {
    write("No.");
    return 1;
    }
}
