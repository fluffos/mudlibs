// Warrior...

inherit "/obj/monster";

void setup() {    
      set_name("warrior");
      set_short("Warrior");
      set_main_plural("Warriors");
      add_triggered_action("bing", "pub_brawl", this_object(), "pub_brawl");
      set_long(
"This is a warrior who is doing his hardest to make Daggerford a safe place "+
"to live.\n");
      set_race("human");
      set_class("fighter");
      set_level(6+random(4));
      adjust_money(random(30),"copper");
      load_chat(5, ({ 1, ":grunts.\n",
      1, "@grunt",
      1, "'Are you trying to provoke me ?",
      1, "'What do you mean ?",
      1, "'Ug.\n"
      }));
      load_a_chat(30, ({
      1, "'YOU'RE GONNA DIE FOR THIS.",
      1, "'Try to make the world a safe place and this happens.",
      1, "'Do you know who I am ?",
      1, "'Wulfgar the Barbarian is a close friend of mine you know."
      }));
      add_move_zone("smithy");
      add_move_zone("city");
      if(random(2))
	new("/baseobs/armours/cape")->move(this_object());
      else
	new("/baseobs/armours/studded")->move(this_object());
      if(random(4))
	new("/baseobs/armours/cape")->move(this_object());
      if(random(10))
	new("/baseobs/armours/cape")->move(this_object());
      if(random(2))
	new("/baseobs/weapons/dagger")->move(this_object());
      else
	new("/baseobs/weapons/knife")->move(this_object());
     this_object()->init_equip();
} /* setup */
