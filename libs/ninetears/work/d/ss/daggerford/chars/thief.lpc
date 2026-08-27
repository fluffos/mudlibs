// Thief...

inherit "/obj/monster";
inherit "/d/ss/daggerford/chars/monster_events";

void setup() {    
      set_name("thief");
      set_short("thief");
      set_main_plural("thieves");
      add_move_zone("pub");
      add_move_zone("city");
	set_random_stats(6, 18);
      set_long(
"This is a member of the thieves guild.  You better be careful.  "+
"He probably has lots of friends.\n");
      adjust_money(1+random(10),"copper");
      add_triggered_action("bing", "pub_brawl", this_object(), "pub_brawl");
      add_triggered_action("bing2", "event_death", this_object(), "death");
      set_race("human");
      set_level(1+random(5));
      set_class("thief");
      load_chat(10, ({
        1, "'Have you paid all your robbery tax this year ?\n",
        1, ":seems to have fallen in love with the sight of your wallet.\n",
        1, ":wanders over to someone and threatens them.\n",
        1, "@peer sus at $lname$",
      }));
      load_a_chat(30, ({
        1, "'Wait till my boss hears about this!",
        1, "'There's someone behind you!",
        1, "'If you leave now, I might forget this incident.",
        1, ":tries to hide in the crowd, but fails."
      }));
      new("/baseobs/weapons/dagger")->move(this_object());
      new("/baseobs/armours/leather")->move(this_object());
      this_object()->init_equip();
} /* setup() */
