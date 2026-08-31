// Owner of the armory in roston.  NS.
#include <std.h>
#include <roston.h>
inherit VENDOR;

create() {
    ::create();
   set_name("Joey");
   set_id( ({ "joey","monster" }) );
    set_short("Joey the armorer");
   set("aggressive", 0);
  set_level(20);
    set_long("Joey will buy or sell you any of your amour needs. <help shop> "
             "will get you a list of available shop commands.");
    set_languages( ({ "farsi" }) );
   set_gender("male");
   set_alignment(40);
   set("race", "dwarf");
   add_money("gold", random(60));
    set_body_type("human");
    set_currency("silver");
    set_storage_room(ROOMS "armory_s");
    set_skill("bargaining", 150);
    set_property("no bump", 1);
    set_property("no attack", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in farsi Noo! "+
      (string)previous_object()->query_cap_name()+" is trying to kill me!");
    return 0;
}
