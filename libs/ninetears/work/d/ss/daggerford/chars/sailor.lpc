// Sailor...

inherit "/obj/monster";

void setup() {    
      set_name("sailor");
      add_alias("seaman");
      add_adjective("drunken");
      set_race("human");
      set_level(1+random(5));
	set_random_stats(6, 18);
      set_short("Sailor");
      add_move_zone("pub");
      add_move_zone("city");
      add_triggered_action("bing", "pub_brawl",  this_object(), "pub_brawl");
      set_long(
"This is a sailor from one of the many countries that trade here.\n"+
"He is roaring drunk.\n");
      adjust_money(random(10), "copper");
      load_chat(10, ({
1, "'You aven't sh'een a pub go pash't ave you ?",
1, "'It wash' here a minute ago.",
1, "'Why are there two of you ?",
1, ":staggers backwards and forwards.",
1, "@burp",
1, "@trip",
1, "@puke",
      }));
      load_a_chat(20, ({
1, "'What I do?, What I do ?",
1, "'Help me guysh!  He'sh picking on me.",
1, "'Boy are you in trroublesh now.",
1, ":swings his fists wildly.",
1, ":trips and runs into a post."}));
      new("/baseobs/weapons/dagger")->move(this_object());
      this_object()->init_equip();
} /* setup() */
