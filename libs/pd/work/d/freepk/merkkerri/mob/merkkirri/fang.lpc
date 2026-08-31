#include <mjungle.h>
#include <std.h>
#include <move.h>
inherit WEAPON;

int weapon_hit(object atk);
create() {
::create();
set_id(({"fang"}));
set_property("no steal", 1);
set_name("fang");
set_short("a fang");
set_long("A fang.  If you have this, you shouldn't and you should report it.");
set_value(0);
set_weight(1);
set_hands(1);
set_wc(11);
set_ac(1);
set_type("melee");
set_hit( (: weapon_hit :) );
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
 

if(random(100) > 75) {
result = (random(40))+((this_player()->query_level()));
atk->add_poisoning(15);
      return result;
   }
return 0;
}

int move(mixed dest) {
  if (environment()) {
    this_object()->remove();
    return MOVE_DESTRUCTED;
  }
  return ::move(dest);
}
