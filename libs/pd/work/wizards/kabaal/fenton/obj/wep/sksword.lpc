#include <std.h>
#include <fenton.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("sword");
   set_short("Skeleton Sword");
   set_long("This sword is finely crafted.  Its been crafted by one of the most skilled "
"weaponsmiths in the land, but for evil rather than good.");
   set_weight(30);
   set_value(260);
   set_type("blade");
   set_wc(15);
   set_id(({"sword", "skeleton sword"}));
}

int check_skill(string str) {
   object ob;
   if (!str) return 0;
   ob = present(str, this_player());

   if (!ob) return 0;
   if (ob != this_object()) return 0;
   if (this_player()->query_paralyzed()) return 0;
   if (this_player()->query_skill("blade") < 80) {
     write("If you wield this you'll cut your arm off.");
     return 1;
   }
   return 0;
}

void init() {
 ::init();
   add_action("check_skill", "wield");
}
