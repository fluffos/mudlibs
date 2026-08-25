// Wandering Wizard...

inherit "/obj/monster";


void setup() {
      int i;
      i = random(13);
      set_name("magician");
      add_alias("wizard");
      set_short("wandering magician");
      set_main_plural("magicians");
      set_race("human");
      set_al(-100+random(201));
    //set_class("wizard");
      set_random_stats(6, 18);
      set_level(i);
      set_wimpy(0);
      // ob->add_attack("spell", 0, 80, i*10, 30, 0, "magic");
      set_max_hp(7+i*6);
      new("/baseobs/armours/cloak")->move(this_object());
      set_long("He looks like a Magician at least. Who else would wear "
         "such a long cloak and have a long white beard ?\n");
      adjust_money(({random(i*5), "copper", random(i), "silver"}));
      load_chat(10,
         ({
               1, "The wizard shuffles away from you.",
               1, "'Hmmm... How did that fireball-spell go again ?",
               1, "'What did you say ?",
               1, "'Ylle bulle srchraff graff hrrrla hrrril sprrt.",
               1, "@sigh",
          }));
      load_a_chat(30,
         ({
               1, "'Die feeble mortal.",
               1, "'Do you know the powers you are messing with.",
               1, ":mutters some strange incantation.",
               1, ":readies some cat-whiskers and a piece of a dragon's claw."
               "Oh, don't worry, it's probably just for casting some spell.",
               1, ":misses you with a spell, destroying a tree instead."
          }));
      add_triggered_action("bing2", "event_death", this_object(), "death");
      this_object()->init_equip();

} /* setup() */
