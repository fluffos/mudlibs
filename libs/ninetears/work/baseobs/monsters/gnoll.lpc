// Gnoll

inherit "/obj/monster";

void setup() {
      set_name("gnoll");
      add_adjective("ugly");
      set_race("monster");
      set_al(60);
      set_aggressive(1);
      set_level(1+random(2));
      set_wimpy(15);
      set_short("ugly gnoll");
      set_main_plural("ugly gnolls");
      add_plural("gnolls");
      set_random_stats(6, 18);
      set_join_fight_mess("An ugly gnoll joins the fight.\n");
      set_long("It's a large hyena-like humanoid.\n");
      load_chat(10,
         ({
               1, ":stares at you in a hostile way.\n",
               1, "'Arrrl urrr marrch errremiii!\n"
          }));
      load_a_chat(30,
         ({
               1, "'Urrrrl DIE!\n",
               1, "'Urrrrl i hrrch ngice hrrrrohi.\n",
               1, "'Grrrrrr!\n"
          }));
      if(random(2))
  	 new("/baseobs/weapons/club")->move(this_object());
      else
	 new("/baseobs/weapons/hand_axe")->move(this_object());
      new("/baseobs/armours/leather")->move(this_object());
      this_object()->init_equip();

} /* setup() */
