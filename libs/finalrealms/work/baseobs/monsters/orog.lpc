// The famous OROG!!!

inherit "/obj/monster";

void setup() {
      set_name("orog");
      add_adjective("big");
      add_adjective("ugly");
      set_short("orog");
      set_al(70);
      set_main_plural("orogs");
      add_move_zone("forest");
      set_long("Ugly big orclike creature.\n");
      set_aggressive(1);
      adjust_money(random(30),"copper");
      set_join_fight_mess("An orog gleefully throws itself into combat.\n");
      set_race("orc");
      set_level(2+random(3));
      set_wimpy(5);
      set_random_stats(6, 18);
      load_chat(10,
         ({
               1, "'Kloss-lunk argchr ?",
               1, "@grin evilly at $lname$",
          }));
      load_a_chat(30,
         ({
               1, "'KLOSS-LUNK, KLOSS-LUNK!",
               1, "'Grrrrrrrr!!!",
               1, ":licks blood off his chin."
          }));
      new("/baseobs/armours/leather")->move(this_object());
      this_object()->init_equip();

} /* setup() */
