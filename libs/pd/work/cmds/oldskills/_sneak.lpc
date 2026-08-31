//      /bin/user/_sneak.c
//      from the Nightmare mudlib
//      rogue ability
//      created by Descartes of Borg 1 june 1993

#include <std.h>
inherit DAEMON;
int abil();

int cmd_sneak(string str) {
    int stealth, dex;

   if (!abil()) {
      write("What?\n");
      return 1;
   }
    if(this_player()->query_ghost()) return 0;
    stealth = (int)this_player()->query_skill("stealth");
    dex = (int)this_player()->query_stats("dexterity");
    if(stealth < 5) {
        notify_fail("You are not quite sly enough to do that.\n");
        return 0;
    }
    if((int)this_player()->query_sp() < 15) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    this_player()->add_sp(-15);
    this_player()->set_property("stealth", 2);
    write("You prepare to sneak around.\n");
    return 1;
}

void help() {
    write("Syntax: <sneak>\n\n"
      "Allows you to make a single move unnoticed.\n"
    );
}

int abil() {
   object ob;
   ob = this_player();
   if (!ob) return 0;
   if (ob->query_class() != "rogue") return 0;
   if (ob->query_skill("stealth") < 5) return 0;
   if (ob->query_level() < 1) return 0;
   return 1;
}
