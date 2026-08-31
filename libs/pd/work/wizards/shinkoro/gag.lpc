#include <std.h>
inherit OBJECT;
int silencer(string str);

void create() {
 ::create();
   set_short("a gag");
   set_name("gag");
   set_long("You do not see that here.");
   set_weight(0);
   set_value(0);
   set_id(({ "gag" }));
}

void init() {
 ::init();
   add_action("silencer", "");
}

int give() {
   if (this_player()->query_name() == "slinker") return 0;
   return 1;
}
int query_auto_load() { return 1; }
int put() { return 1; }
int drop() {
   if (this_player()->query_name() == "slinker") return 0;
   return 1;
}
int bury() {
   if (this_player()->query_name() == "slinker") return 0;
   return 1;
}
int dest() {
   if (this_player()->query_name() == "slinker") return 0;
   return 1;
}

int silencer(string str) {
   string inf;
   if (!str) return 0;
   if (this_player()->query_name() == "slinker") return 0;
   inf = query_verb();
   switch(inf) {
     case "newbie":
     case "say":
     case "fighter":
     case "rogue":
     case "mage":
     case "kataan":
     case "cleric":
     case "monk":
     case "cre":
     case "intercre":
     case "council":
     case "gossip":
     case "dragon":
     case "assassin":
     case "admin":
     case "berserker":
     case "tell":
     case "emoteto":
     case "echo":
     case "party line":
     case "emote":
     case "echoto":
     case "echoall":
     case "hm":
       write("You have been gaged.");
       return 1;
     default:
       return 0;
   }
   return 0;
}
