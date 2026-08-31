#include <guild.h>
inherit "/std/vendor";

create() {
    ::create();
   set_name("michael");
   set_id( ({ "michael" }) );
    set_short("Michael, The shop attendant");
   set("aggressive", 0);
  set_level(45);
    set_long("Fallen from his place among the heavans, Michael has decided to take up with Acheron. Type <help shop> for a list of commands.");
    set_languages( ({ "annarian" }) );
   set_gender("male");
   set_alignment(-420);
   set("race", "sackrarl");
   add_money("gold", random(60));
    set_body_type("scorpion");
    set_currency("gold");
    set_storage_room(ROOMS"acheron/storage");
    set_skill("bargaining", 150);
    set_property("no bump", 1);
    set_property("no attack", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in farsi "+
      (string)previous_object()->query_cap_name()+" is about to die!");
    return 0;
}
