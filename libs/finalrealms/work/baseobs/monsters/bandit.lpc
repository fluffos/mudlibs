// The infamous BANDIT!

inherit "/obj/monster";

void setup() {
      set_name("bandit");
      add_alias("road-bandit");
      set_al(40);
      set_short("bandit");
      set_race("human");
      set_level(3+random(2));
      set_wimpy(0);
      add_alias("robber");
      set_random_stats(6, 18);
      set_long("This is a vicious and ammoral road-bandit. "
         "He's probably here to rob you.\n");
      adjust_money(10+random(20),"copper");
      load_chat(10,
         ({
               1, "'Your money or your valueless life please.",
               1, ":moves over to you and demands to have all your money.",
          }));
      load_a_chat(30,
         ({
               1, "'Don't you dare have no money in your corpse!",
               1, "'Gimme your money, and I'll let you live.",
               1, "'Taste THIS!",
               1, "'Ouch!",
               1, "@grin wickedly $lname$",
          }));
      if(random(4))
	 new("/baseobs/weapon/long_sword")->move(this_object());
      else
	 new("/baseobs/weapon/short_sword")->move(this_object());
      new("/baseobs/armour/leather")->move(this_object());
      set_join_fight_mess("A bandit enters the combat-fray.\n");
      this_object()->init_equip();

} /* setup() */
