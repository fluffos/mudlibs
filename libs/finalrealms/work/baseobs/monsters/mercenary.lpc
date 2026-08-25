// Wandering Mercenary...

inherit "/obj/monster";

void setup() {
      set_name("mercenary");
      add_adjective("tough");
      set_race("human");
      set_al(-90+random(161));
      set_short("mercenary");
      set_level(4+random(8));
      set_wimpy(0);
      set_random_stats(6, 18);
      set_str(roll(1, 4)+14);
      set_long(
         "A tough battled scarred mercenary.  There are better ways of "
	 "filling in an afternoon than messing with the likes of him.\n");
      adjust_money(({random(10),"silver", random(100), "copper"}));
      load_chat(10,
         ({
               1, "'Anyone you don't like?\n",
               1, "'I'll do anything if the price is right?\n",
               1, "'Don't get me angry.  You won't like me when I'm angry.\n"
          }));
      load_a_chat(30,
         ({
               1, "'I'll show you whose boss\n",
               1, "'You think you're so tough\n",
               1, "'Finally a fight. Pity it's my day off though.\n"
          }));
      if(random(2))
	 new("/baseobs/weapons/bastard_sword")->move(this_object());
      else
	 new("/baseobs/weapons/long_sword")->move(this_object());
      new("/baseobs/armours/chainmail")->move(this_object());
      this_object()->init_equip();

} /* setup() */
