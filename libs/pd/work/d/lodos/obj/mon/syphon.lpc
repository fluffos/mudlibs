#include <lodos.h>
#include <std.h>
inherit "/std/vendor";

create() {
 ::create();
   set_name("syphon");
   set_id( ({ "syphon" }));
   set_short("Syphon, master of armour");
   set("aggressive", 0);
   set_level(22);
   set_long("A retired blacksmith,  now sells that "
            "which he once made. <help shop> will give you a "
            "list of shop commands.");
   set_languages(({ "farsi" }));
   set_gender("male");
   set_alignment(100);
   set("race", "elf");
  set_type(({ "armour" }));
   add_money("gold", random(60));
   set_body_type("human");
   set_currency("gold");
   set_storage_room(ROOMS"arm_stor");
   set_skill("melee",100);
//   set_property("no attack", 1);
   set_skill("bargaining", 100);
   set_property("no bump", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in farsi Help!! I am being attacked by "+
      (string)previous_object()->query_cap_name());
    return 0;
}
