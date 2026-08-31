// Owner of the general store in roston -(Inferno)-
inherit "/std/vendor";

create() {
    ::create();
   set_name("percivus");
   set_id( ({ "percivus" }) );
    set_short("Percivus, the general store owner");
   set("aggressive", 0);
  set_level(20);
    set_long("Percivus will buy just about anything. <help shop> "
             "will get you a list of available shop commands.");
    set_languages( ({ "farsi" }) );
   set_gender("male");
   set_alignment(40);
   set("race", "dwarf");
   add_money("gold", random(600));
    set_body_type("human");
    set_currency("gold");
    set_storage_room("/wizards/detach/roston/storage");
    set_skill("bargaining", 150);
    set_property("no bump", 1);
    set_property("no attack", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in farsi Help!! I am being attacked by "+
      (string)previous_object()->query_cap_name());
    return 0;
}
