inherit "/std/vendor";

void create() {
 ::create();
   set_name("tirith");
   set_id( ({ "tirith", "vendor", "shop keeper", "keeper", "shopkeeper", "nerd" }) );
   set_short("Tirith, owner of the Elite Supply Shop");
   set("aggressive", 0);
   set_level(50);
   set_long("He will buy your equipment from you and keep it safe from "
      "others.");
   set_languages( ({ "selunian" }) );
   set_gender("male");
   set_alignment(340);
   set("race", "human");
   set_exp(0);
   add_money("gold", random(500));
   set_body_type("human");
   set_currency("gold");
   set_storage_room("/d/standard/tstorage");
   set_skill("melee",100);
   set_skill("bargaining", 170);
   set_property("no bump", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in selunian Help!! I am being attacked by "+
      (string)previous_object()->query_cap_name());
    return 0;
}
