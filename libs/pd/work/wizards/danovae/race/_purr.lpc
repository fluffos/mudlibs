
#include <std.h>
#include <daemons.h>

#define _KITTY "/wizards/danovae/race/purring"

inherit DAEMON;

int cmd_purr(string str) {
   if(this_player()->query_current_attacker())
     return notify_fail("You are not calm enough to purr.\n");
   if(this_player()->query_riding())
     this_player()->force_me("dismount");
   new(_KITTY)->move(this_player());
   return 1;
}

int abil() {
   object b;
   b = this_player();
   if(!b) return 0;
   if(this_player()->query_race() != "bastet") return 0;
   return 1;
}

void help() {
   write("Syntax: <purr>\nA faster way for felines to heal themselves.\n<purr> to start purring.\n<cease> to stop purring.");
}

