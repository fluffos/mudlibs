inherit "/std/vendor";

create() {
 ::create();
   set_name("starburst");
   set_id(({ "starburst", "shopkeeper", "storekeeper", "keeper" }));
   set_short("Starburst, the general store shopkeeper");
   set("aggressive", 0);
   set_level(30);
   set_long("Starburst is the owner of the Tirun General Supply Shop. She will "
     "break your legs if she catches you in the back room. Her supplies are "
     "guarded jealously. <help shop> will get you a list of shop commands.");
   set_languages( ({ "pulchra" }) );
   set_type(({ "other", "object" }));
   set_gender("female");
   set_alignment(400);
   set("race", "human");
   add_money("gold", random(90));
   set_body_type("half-elf");
   set_currency("gold");
   set_storage_room("/d/nopk/tirun/storage1");
    set_exp(1);
   set_skill("melee",100);
   set_skill("bargaining", 75);
   set_property("no bump", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in pulchra Help!! I am being attacked by "+
      (string)previous_object()->query_cap_name());
    return 0;
}
