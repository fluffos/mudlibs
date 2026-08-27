// Assassin...

inherit "/obj/monster";

void setup() {    
      set_name("mercenary");
      add_adjective("mean");
      set_race("human");
      set_class("assassin");
      add_move_zone("city");
      set_level(6+random(6));
	set_random_stats(6, 18);
      set_short("Mean Mercenary");
      set_main_plural("mean mercenaries");
      add_plural("mercenaries");
      add_triggered_action("bing", "pub_brawl", this_object(), "pub_brawl");
      add_triggered_action("bing2", "event_death", this_object(), "death");
      set_long(
"This is a mean mercenary.  He is wearing a stylish robe.  From his "+
"looks you get the impression he is not going to like being bothered.\n");
      load_chat(10, ({
        1, ":stares at you in a strange way.",
        1, ":seems to be watching you."
      }) );
      load_a_chat(30, ({
        1, "'you'll be sorry for this.",
        1, "'Just wait till I tell Angelica.",
        1, "'Ouch!"
      }) );
      if(random(2))
	new("/baseobs/weapons/dagger")->move(this_object());
      new("/baseobs/armours/cape")->move(this_object());
      this_object()->init_equip();
} /* setup */
