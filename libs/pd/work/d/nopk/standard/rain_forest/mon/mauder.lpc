#include <rain.h>
#include <std.h>
inherit "/std/vendor";

create() {
   ::create();
   set_name("mauder");
   set_id(({ "mauder" }));
   set_short("Mauder, the general store manager");
   set_level(10);
   set_long("Mauder is a small stumpy elf who manages the general store."
            "Type <help shop> for more information");
   set_languages( ({ "elfish" }) );
   set_gender("male");
   set_alignment(40);
   set_race("elf");
   add_money("gold", random(600));
   set_body_type("human");
   set_currency("gold");
   set_storage_room(ROOMS"storage3");
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
