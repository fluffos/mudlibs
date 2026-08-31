inherit "/std/vendor";

void create() {
 ::create();
   set_name("drendun");
   set_id(({ "official", "shopkeeper", "drendun", "keeper" }));
   set_short("Drendun, Shopkeeper of the Tirun Armoury");
   set("aggressive", 0);
   set_level(12);
   set_long("The halfling is employed by the Tirun government to run this shop. "
     "He only buys armour, but he will not haggle quite as much as some of the "
     "other shopkeepers who own their own businesses. <help shop> will get you "
     "a list of available commands. Drendun looks like the sort of person that "
     "pockets some of the profit from the store."
   );
   set_languages(({ "selunian" }));
   set_type(({ "armour" }));
   set_gender("male");
   set_alignment(-100);
   set("race", "halfling");
   set_hp(480);
   add_money("silver", random(300));
   set_body_type("human");
   set_currency("gold");
   set_storage_room("/d/standard/astorage");
   set_skill("melee", 100);
   set_skill("bargaining", 85);
   set_property("no bump", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in selunian Help!! I am being attacked by "+
      (string)previous_object()->query_cap_name());
    return 0;
}
