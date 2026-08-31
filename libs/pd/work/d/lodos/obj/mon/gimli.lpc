#include <lodos.h>
#include <std.h>
inherit "/std/vendor";

int check_who();

create() {
 ::create();
   set_name("gimli");
   set_id(({ "gimli", "dwarf", "gimli son of gloin", "son of gloin" }));
   set_short("Gimli");
   set("aggressive", check_who() );
   set_level(35);
   set_long("Gimli, son of Gloin from the sleepy mountain is the proud "
     "owner of this weaponry. He does not plan on staying here quite to "
     "his dying day, or much longer for ther matter, but for the moment "
     "he tends this shop.");
   set_languages(({ "malkierien" }));
   set_gender("male");
   set_alignment(100);
   set_race("dwarf");
   set_type(({ "weapon" }));
   add_money("gold", random(60));
   set_body_type("human");
   set_currency("gold");
   set_storage_room(ROOMS"wep_stor");
   set_skill("melee",100);
   set_skill("bargaining", 100);
   set_property("no bump", 1);
}

int check_who() {
   if (this_player()->query_race_() == "orc") {
     force_me("shout in malkierien Die foul orc!");
     return 900;
   }
   return 0;
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in malkierien Khazad ai menu! "+
      (string)previous_object()->query_cap_name()+" will pay in blood!");
    return 0;
}
