// Wizard...

inherit "/obj/monster";

void setup() {    
      int i;
      i = 5+random(8);
      set_name("wizard");
      add_alias("magician");
      set_short("Wizard");
      set_main_plural("wizards");
      set_race("human");
      set_class("wizard");
      set_level(i);
      add_move_zone("city");
      add_move_zone("pub");
	set_random_stats(6, 18);
      set_long(
"This is a wizard of the Wizards Guild.  He is a powerful wizard "+
"by the looks of his uniform.  You'd best leave him alone.\n");
      adjust_money(random(i*4), "copper");
      load_chat(10, ({
        1, ":shuffles away from you.\n",
        1, "'Not now please, I'm very busy.\n",
        1, "'What did you say?\n",
        1, "'Have you seen a pipe?  One of the senior wizards " +
        "has lost his.\n",
        1, "@sigh",
      })); 
      load_a_chat(30, ({
        1, "'Die feeble mortal.",
        1, "'Do you know the powers you are messing with.",
        1, ":mutters some strange incantation.",
        1, "The crowd flee in terror.",
        1, ":misses you and a spectator vanishes."
      }));
//      set_weap_skill("magic");
      // ob->add_attack("spell", 0, 20, random(i*10), 100, 0, "magic");
      add_move_zone("tavern");
} /* setup() */
