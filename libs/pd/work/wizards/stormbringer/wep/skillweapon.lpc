
#include <std.h>
inherit WEAPON;

create() {
    ::create();
    set_id( ({ "dagger", "rusty dagger" }) );
    set_name("dagger");
    set_short("A rusty dagger");
    set_long("An old dagger someone just threw out.\n");
    set_mass(7);
    set_value( 25);
    set_wc(8);
    set_ac(1);
    set_type("knife");
    set_wield("It's yucky, but it wields.");
}

int check_skill(string str) {
   object ob;
   if (!str) return 0;
   ob = present(str, this_player());
   if (!ob) return 0;
   if (ob != this_object()) return 0;
   if (this_player()->query_paralyzed()) return 0;
   if (this_player()->query_skill("knife") < 20) {
     write("You are not skilled enough to wield this blade.");
     return 1;
   }
   return 0;
}

void init() {
 ::init();
   add_action("check_skill", "wield");
}
