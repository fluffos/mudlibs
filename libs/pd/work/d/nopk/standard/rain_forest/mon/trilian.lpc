#include <rain.h>
#include <std.h>
inherit "/std/vendor";

create() {
   ::create();
   set_name("trilian");
   set_id( ({ "trilian" }) );
   set_short("Trilian, the armour keeper");
   set("aggressive", 0);
   set_level(30);
   set_long("Trilian is a tall elf that watches the armour shop. Type "
            "<help shop> for more information");
   set_type(({ "armour" }));
   set_languages( ({ "elfish" }) );
   set_gender("male");
   set_alignment(40);
   set("race", "elf");
   add_money("electrum", random(600));
   set_body_type("human");
   set_currency("gold");
   set_storage_room(ROOMS"storage2");
   set_skill("bargaining", 150);
   set_property("no bump", 1);
   set_property("no attack", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in eltherian Help!! I am being attacked by "+
    (string)previous_object()->query_cap_name());
    return 0;
}
