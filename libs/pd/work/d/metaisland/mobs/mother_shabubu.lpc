#include <std.h>
#include <metallicana.h>
inherit "/std/vendor";
create() {
    ::create();
   set_name("mother shabubu");
   set_id( ({ "shabubu", "Mother Shabubu" }) );
   set_short("Mother ShaBuBu");
   set("aggressive", 0);
   set_level(45);
   set_long("Mother Shabubu is a small faerie that has come to make this forrest her home. She has been studing the ways "
            "of the Shaman for many years and has a Sharmaic symbol on her arm.");
   set_languages( ({ "farsi" }) );
   set_gender("female");
   set_alignment(500);
   set("race", "faerie");
   add_money("gold", random(60));
   set_body_type("faerie");
   set_currency("gold");
   set_storage_room(ROOMS "storage");
   set_skill("bargaining", 200);
   set_property("no bump", 1);
   set_property("no attack", 1);
}
int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in farsi "+
      (string)previous_object()->query_cap_name()+" is about to die!");
    return 0;
}
