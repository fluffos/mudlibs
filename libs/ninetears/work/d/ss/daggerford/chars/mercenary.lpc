// Mercenary...

inherit "/obj/monster";

void setup() {    
      set_name("mercenary");
      add_adjective("tough");
      set_race("human");
      set_class("fighter");
      add_move_zone("city");
	set_random_stats(6, 18);
      set_level(13);
      add_triggered_action("bing", "pub_brawl",  this_object(), "pub_brawl");
      set_long(
"A tough battled scarred mercenary.  There are better ways of filling in " +
"an afternoon that messing with the likes of him.\n");
      adjust_money(100 + random(100), "copper");
      load_chat(10, ({
        1, "'Anyone you don't like ?",
        1, "'I'll do anything if the price is right?",
        1, "'Don't get me angry.  You won't like me when I'm angry."
      }));
      load_a_chat(30, ({
        1, "'I'll show you who's boss.",
        1, "'You think your so tough!",
        1, "The crowd run in terror as the Mercenary swing wildly around "+    
           "himself."
      }));
      new("/baseobs/weapons/dagger")->move(this_object());
      new("/baseobs/armours/chainmail")->move(this_object());
      this_object()->init_equip();
} /* setup */
