inherit "/std/vendor";

create() {
    ::create();
   set_name("roger");
   set_id( ({ "roger", "vendor", "shop keeper", "keeper", "shopkeeper", "nerd" }) );
   set_short("Roger, the shop keeper of the Asgard weaponry.");
   set("aggressive", 0);
  set_level(12);
    set_long("Roger will buy and sell all types of "
             "weapons. Type <help shop> to get a list "
             "of available shop commands.");
    set_languages( ({ "farsi" }) );
   set_gender("male");
   set_alignment(0);
   set("race", "elf");
   store_type("weapon");
   set_hp(480);
   add_money("gold", random(30));
    set_body_type("human");
    set_currency("gold");
    set_storage_room("/d/standard/frealmz/storage");
   set_skill("melee",100);
    set_skill("bargaining", 100);
    set_property("no bump", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in farsi Help!! I am being attacked by "+
      (string)previous_object()->query_cap_name());
    return 0;
}
