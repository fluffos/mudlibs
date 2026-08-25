// The fearsome BULLYWUG!

inherit "/obj/monster";


void setup() {
         set_name("bullywug");
         add_adjective("frog");
         set_race("bullywug");
	 set_random_stats(6, 18);
         set_level(3+random(2));
         set_al(50);
         set_long("The bullywug is a bipedal frog-like amphibian. "
                "It has a smooth, mottled olive-green hide.\n");
         set_main_plural("bullywugs");
         set_short("bullywug");
         load_chat(10,
         ({
                1, "'Crrrk crrrroa grrrrk.",
                1, "'Hrrrl chrrrra!",
                1, "'Grub uurch chrh srrckur!",
                1, ":gives a sign with his tongue towards the bushes.",
                1, "@drool $lname$",
         }));
         load_a_chat(20,
         ({
                1, "'Croooack croooack!",
                1, ":croaks.",
         }));
	 new("/baseobs/weapons/bastard_sword")->move(this_object());
	 new("/baseobs/armours/leather")->move(this_object());
         set_join_fight_mess("A bullywug happily exclaims: Cooooorak!.\n");
         add_triggered_action("bing2", "event_death", this_object(), "death");
         this_object()->init_equip();

} /* setup() */
