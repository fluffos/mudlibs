#include <swamp.h>
#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
create() {
::create();
set_id(({"claw"}));
set_name("claw");
set_short("claw");
set_long("A ghast claw.  If you have this, you shouldn't and you should report it to Asmodeus right after you bury it.");
set_value(0);
set_weight(1);
set_wc(15);
set_ac(1);
set_type("blade");
set_hit( (: weapon_hit :) );
set_hands(1);
set_wield("You shouldn't have this.  Bury it now!");
}

void init() {
 ::init();
add_action("Destruct", "unwield");
}

int Destruct(string str) {
   if (!str) return 0;
   if (present(str, this_player()) != this_object()) return 0;
   this_object()->remove();
   return 1;
}

int weapon_hit(object atk) {
   int result;

if(random(100) > 88) {
result = (random(30))+((this_player()->query_level()));
atk->add_poisoning(45);
      return result;
   }
return 0;
}
