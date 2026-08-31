inherit "/std/vendor";
#include <roston.h>

create() {
    ::create();
   set_name("anubis");
   set_id( ({ "anubis" }) );
    set_short("%^BOLD%^%^WHITE%^Anubis of the Dead");
   set("aggressive", 0);
  set_level(45);
    set_long("%^BOLD%^%^BLACK%^Anubis was once the god of the dead, but after "
      "Osiris' reign, Anubis fled to the darksouls. <help shop> "
      "for commands.");
    set_languages( ({ "farsi" }) );
   set_gender("male");
   set_alignment(-420);
   set("race", "jackel");
   add_money("gold", random(600));
    set_body_type("quadrupe");
    set_currency("gold");
    set_storage_room(DARKSOUL"storage");
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
