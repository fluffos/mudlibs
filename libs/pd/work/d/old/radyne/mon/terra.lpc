#include <std.h>
inherit "/std/vendor";

void create() {
 ::create();
   set_name("Terra");
   set_id(({ "terra", "shopkeeper", "storekeeper", "keeper" }));
   set_short("Terra, Radyne General Shopkeeper");
   set("aggressive", 0);
   set_level(30);
   set_long(
     "She is a jolly, cheerful elf happy to help with your shopping needs, granted it's in her shop of course.\n<help shop> go get more information."
   );
   set_type(({ "other", "object" }));
   set_gender("female");
   set_alignment(400);
   set_race("elf");
   add_money("gold", random(90));
   set_body_type("human");
   set_currency("gold");
   set_storage_room("/d/radyne/nova/rooms/rs_storage");
   set_skill("melee",100);
   set_skill("bargaining", 75);
   set_property("no bump", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in pulchra Help!! I am being attacked by "+
      (string)previous_object()->query_cap_name());
    return 0;
}
