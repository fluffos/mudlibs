#include <std.h>
#include <mjungle.h>
#include <gcity.h>

inherit MOB+"queen";

int illu();

void create() {
  ::create();
  set_spells(query_spells() + ({ "fear" }) );
  set_die((: illu() :));
  set_level(30);
  set_stats("wisdom", 200);
  set_max_hp(500);
  set_hp(500);
  set_exp(1332);
}

int illu() {
   object ob;
   tell_room(environment(this_object()),
     "The queen vanishes!  It was just an illusion!", ({ }) );
   catch ( this_object()->remove() );
   return 0;
}
