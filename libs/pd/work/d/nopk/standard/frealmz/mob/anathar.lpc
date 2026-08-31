inherit "/std/vendor";

create() {
    ::create();
   set_name("anathar");
   set_id( ({ "anathar", "vendor", "shop keeper", "keeper", "shopkeeper", "nerd" }) );
   set_short("Anathar, master armoursmith.");
   set("aggressive", 0);
  set_level(30);
   set_long("A retired blacksmith, Anathar now sells that "
            "which he once made. <help shop> will give you a "
            "list of shop commands.");
    set_languages( ({ "farsi" }) );
   set_gender("male");
   set_alignment(0);
   set("race", "elf");
   store_type("armour");
   add_money("electrum", random(200));
    set_body_type("human");
    set_currency("gold");
    set_storage_room("/d/standard/frealmz/arm_stor");
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
