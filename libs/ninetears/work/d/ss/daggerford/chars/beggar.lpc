// Beggar...

inherit "/obj/monster";

void setup() {    
      set_name("beggar");
      set_short("Poor beggar");
      set_main_plural("Poor Beggars");
      add_alias("beggar");
      set_race("human");
      add_move_zone("city");
	set_random_stats(6, 18);
      set_level(-3+random(3));
      set_long(
"This is a poor beggar.  Perhaps you should give him some money.\n");
      adjust_money(random(100), "copper");
      load_chat(10, ({
1, "'Money for the poor.",
1, "'Please give me some money.",
1, ":pulls on your leg.",
1, ":rattles his tin.",
1, ":mutters something about a wife and 7 children.",
1, ":looks at you with big brown eyes.",
1, "'who will help me ?",
1, ":looks down at the ground and sobs."
      }));
} /* setup */
