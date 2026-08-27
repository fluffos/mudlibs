// Officer of the Militia...

inherit "/obj/monster";

void setup() {    
      set_name("officer");
      add_adjective("militia");
      set_race("human");
      set_class("fighter");
	set_random_stats(6, 18);
      set_level(8+random(7));
      set_short("Officer of the Militia");
      set_main_plural("Officers of the Militia");
      set_long(
"This is an Officer of the Militia. His job is to patrol Daggerford and "+
"keep it safe.\n");
      load_chat(2, ({
1, "'Move along, Move along.",
1, "'Lets not be loitering then.",
1, "'You look suspicious.  Move on and I'll forget I saw you.",
1, ":twirls his batton.",
1, "@eye $lname$",
      }));
      load_a_chat(20, ({
1, "'I'm sorry. You seem to be a honorable fellow after all.",
1, "'I'm prepared to forget this if you let me go.",
1, "'Mummy!",
1, "'Guards!!!!"
      }));
      add_move_zone("barracks");
      new("/baseobs/weapons/long_sword")->move(this_object());
      new("/baseobs/armours/leather")->move(this_object());
      this_object()->init_equip();
} /* setup() */
