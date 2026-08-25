// A Wandering Warrior...

inherit "/obj/monster";

void setup() {
      set_name("warrior");
      set_short("warrior");
      set_main_plural("warriors");
      set_long("Just a wandering warrior.\n");
      set_race("half-orc");
      set_level(random(11));
      set_wimpy(0);
      set_random_stats(6, 18);
      set_al(-100+random(201));
      adjust_money(100+random(400), "copper");
      load_chat(10,
         ({
               1, "@spit $hcname$",
               1, "@grunt",
               1, "'Are you trying to provoke me ?",
               1, "'Are you a spell-caster ?  I just love thrashing those!",
               1, "'Go suck yourself, wimp!"
          }));
      load_a_chat(30,
         ({
               1, "'YOU'RE GONNA DIE FOR THIS.",
               1, "'Let's see who's boss here $acname$",
               1, "'Ughh!",
               1, "'Don't you dare leave in the middle of my fight!"
          }));
      if(random(2))
	 new("/baseobs/armours/chainmail")->move(this_object());
      else
	 new("/baseobs/armours/ringmail")->move(this_object());
      new("/baseobs/weapons/bastard_sword")->move(this_object());
      this_object()->init_equip();

} /* setup() */
