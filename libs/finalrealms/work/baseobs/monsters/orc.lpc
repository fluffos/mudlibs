// Orc...

inherit "/obj/monster";


void setup() {
      set_name("orc");
      set_short("orc");
      set_al(60);
      set_main_plural("orcs");
      add_alias("monster");
      set_race("orc");
      set_level(1+random(2));
      set_wimpy(0);
      set_random_stats(6, 18);
      set_long("This is an orc, an aggressive mammalian carnivore.\n");
      adjust_money(random(300), "brass");
      set_aggressive(1);
      load_a_chat(30,
         ({
               1, "'Eh humin! Niis itin! FODDER!!",
               1, "@growl",
               1, "@grin evilly $lname$",
               1, ":pokes it's teeth.",
               1, "@growls nastily $lname$",
               1, ":looks at you with big red eyes.",
          }));
      set_join_fight_mess("An orc joins the fight.\n");
      add_triggered_action("bing2", "event_death", this_object(), "death");
//      add_triggered_action("regen", "death", this_object(), "regen_after_death");
} /* setup() */
