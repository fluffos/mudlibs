#include <std.h>
inherit "/std/vendor";

void create() {
 ::create();
   set_name("morian");
   set_id( ({ "morian", "expert", "lighting expert", "vendor" }));
   set_short("Morian, the lighting expert");
   set("aggressive", 0);
   set_level(11);
   set_long("For many long years, Morian has worked in this shop. He is a master "
     "at lighting. You can <help shop> for some help in buying and selling.");
   set_languages( ({ "selunian" }) );
   set_gender("male");
   set_alignment(40);
   set_race("human");
   add_money("gold", random(200));
   set_type(({ "light" }));
   set_body_type("human");
   set_currency("gold");
   set_storage_room("/d/standard/lights");
   set_skill("melee",100);
   set_skill("bargaining", 86);
   set_property("no bump", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in selunian Help!! I am being attacked by "+
      (string)previous_object()->query_cap_name());
    return 0;
}
