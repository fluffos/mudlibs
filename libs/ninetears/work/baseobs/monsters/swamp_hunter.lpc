// Hunter...

inherit "/obj/monster";

void setup() {
         set_name("hunter");
         set_short("hunter");
         add_adjective("swamp");
         set_main_plural("hunters");
         set_long("Just a swamp hunter.\n");
         set_race("half-orc");
       //set_class("fighter");
	 set_random_stats(6, 18);
         set_level(random(10));
         set_wimpy(0);
         set_al(-100+random(201));
         adjust_money(random(70), "copper");
         load_chat(10,
         ({
                1, "@search",
                1, "@grunt",
                1, "'These swamps are MY hunting grounds!",
                1, "'I hope you haven't come for a crocodile-hunt.",
                1, "'What are you doing here ?"
         }));
         load_a_chat(30,
         ({
                1, "'Get outta here!",
                1, "@spit $lname$",
                1, "'Ughh!",
                1, "@drool"
         }));
         if(random(2))
	   new("/baseobs/armours/leather")->move(this_object());
         if(random(2))
	   new("/baseobs/weapons/short_sword")->move(this_object());
        this_object()->init_equip();

} /* setup() */
