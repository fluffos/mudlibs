// Goblin! *puke*

inherit "/obj/monster";

void setup() {
      set_name("goblin");
      add_adjective("ugly");
      add_adjective("little");
      set_al(30);
      set_short("goblin");
      set_main_plural("goblins");
      set_random_stats(6, 18);
      set_long("Just an ugly little humanoid.\n");
      set_aggressive(1);
      adjust_money(random(10),"brass");
      set_join_fight_mess("A goblin gleefully throws itself into combat.\n");
      set_race("goblin");
      set_level(random(2));
      set_wimpy(0);
      load_chat(10,
         ({
               1, "'Bree-yark argchr ?",
               1, "@grin evilly at $lname$",
          }));
      load_a_chat(30,
         ({
               1, "'BREE-YARK, BREE-YARK!",
               1, "'Grrrrrrrr!!!",
               1, ":tries to bite you."
          }));
      new("/baseobs/weapons/dagger")->move(this_object());
      if(random(2))
	 new("/baseobs/armours/leather")->move(this_object());
      this_object()->init_equip();

} /* setup() */
