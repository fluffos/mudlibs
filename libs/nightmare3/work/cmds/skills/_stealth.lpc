//      /bin/user/_stealth.c
//      from the Nightmare mudlib
//      rogue ability
//      created by Descartes of Borg 10 april 1993

#include <std.h>

inherit DAEMON;

int cmd_stealth(string str) {
    int stealth, dex;

   if(str=="on") {
    if(this_player()->query_ghost()) return 0;
    stealth = (int)this_player()->query_skill("stealth");
    dex = (int)this_player()->query_stats("dexterity");
    if(stealth < 15) {
        notify_fail("You are not quite sly enough to do that.\n");
        return 0;
    }
    if((int)this_player()->query_sp() < 30) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    this_player()->set_property("stealth", stealth+dex);
    write("You blend in with your surroundings to move with stealth.\n");
    return 1;
   }
   if(str=="off") {

     if(this_player()->query_property("stealth")) {
        write("Stealth off.");
        this_player()->set_property("stealth", 0);
        return 1;
     }

     notify_fail("Stealth is not turned on!\n");
     return 0;
   }

   else {
     notify_fail("Correct syntax: <stealth> <on|off>\n");
     return 0;
   }
}

void help() {
    write("Syntax: <stealth> <on|off>\n\n"
      "Allows you to move without being noticed by other players.\n"
    );
}
