inherit "/obj/monster";

void setup() {
      set_name("forlarren");
      add_adjective("little");
      set_al(60);
      set_short("forlarren");
      set_main_plural("forlarrens");
      set_random_stats(6, 13);
set_long("This creature looks like a cross between a devil and a nymph. "
   "It has goats legs and horns on its head.\n");
      set_aggressive(0);
      adjust_money(random(10),"copper");
      set_join_fight_mess("A forlarren gleefully throws itself into combat.\n");
      set_race("forlarren");
      set_level(random(3));
      set_wimpy(0);
      load_chat(10,
         ({
      1, "'I'm going to make you pay, skin you alive I will!",
               1, "@grin evilly at $lname$",
          }));
      load_a_chat(30,
         ({
               1, "'KILL, KILL, KILL!",
               1, "'Grrrrrrrr!!!",
               1, ":tries to stab you."
          }));
      new("/baseobs/weapons/dagger")->move(this_object());
      if(random(2))
	 new("/baseobs/armours/cloak")->move(this_object());
      this_object()->init_equip();

} /* setup() */
