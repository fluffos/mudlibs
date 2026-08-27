#define MONSTER "obj/monster"
#define ARMORY "obj/handlers/armoury"
#define HOSPITAL "/d/ss/monsters/wm_swamp"

inherit "std/room";

int *swamp_chance, swamp_tot_chance, i;
string *swamp_monsters;


object get_monster(string type)
{
 object ob, ob2;
 int temp, rand, loop;

 if(!swamp_monsters)
 {
	swamp_monsters =
	({
	 "lizard-man", "muck-dweller", "lizard", "snake", "ceratosaur",
	 "bullywug", "crocodile", "hunter", "centipede", "alligator",
	 "toad", "animal", "hermit", "catoblepas","cantobele"
	});
 }
 if(!swamp_chance)
 {
		swamp_chance =
		({
			10, 5, 10, 10, 5,
			5, 5, 5, 10, 5,
			10, 10, 5, 2, 3
		});
		swamp_tot_chance = 100;
 }
 switch(type)
 {
	case "swamp":
	 rand = random(swamp_tot_chance - swamp_chance[sizeof(swamp_chance) - 1]);
	 temp = 0;
	 loop = 0;
	 while(rand > temp)
		temp += swamp_chance[loop++];
	 ob2 = get_monster(swamp_monsters[loop]);
	 ob2->add_move_zone("swamp");
	 ob2->add_property("monster_type", type);
	 return ob2;
	case "crocodile":
	 ob = clone_object(MONSTER);
	 ob->set_name("crocodile");
	 ob->add_alias("reptile");
	 ob->add_adjective("green");
	 ob->add_adjective("large");
	 ob->set_short("crocodile");
	 ob->set_main_plural("crocodiles");
	 ob->set_race("reptile");
	 ob->set_level(5+random(3));
	 ob->set_long("This is a large green crocodile.\n");
	 ob->load_chat(2,
	 ({
		1, ":crawls away from you.",
		1, ":opens it's mouth and heads in your direction.",
		1, ":strethes lazily in the sun.",
		1, ":relaxes back into the water.",
		1, "@yawn boredly",
	 }));
	 ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
	 ob->add_property("monster_type", type);
	 // ob->add_attack("bash", 0, 20, 100, -20, 0, "blunt");
	 return ob;
	case "centipede":
	 ob = clone_object(MONSTER);
	 ob->set_name("centipede");
	 ob->set_short("giant centipede");
	 ob->add_adjective("giant");
	 ob->add_adjective("black");
	 ob->set_main_plural("centipedes");
	 ob->add_move_zone("forest");
	 ob->set_long("A giant black centipede.\n");
	 ob->set_aggressive(1);
	 ob->join_fights("An centipede gleefully throws itself into combat.\n");
	 ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
	 ob->set_race("snake");
	 ob->set_level(1+random(2));
	 ob->set_wimpy(0);
	 ob->add_property("monster_type", type);
	 return ob;
	case "alligator":
	 ob = clone_object(MONSTER);
	 ob->set_name("alligator");
	 ob->set_al(-30);
	 ob->set_short("alligator");
	 ob->add_alias("reptile");
	 ob->add_adjective("aggressive");
	 ob->set_main_plural("alligators");
	 ob->set_long("This is an aggressive repile called an alligator.\n");
	 ob->set_aggressive(1);
	 ob->join_fights("A alligator crawls into the combat fray.\n");
	 ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
	 ob->set_race("reptile");
	 ob->set_level(4+random(4));
	 ob->add_property("monster_type", type);
	 return ob;
	case "lizard-man":
	 ob = clone_object(MONSTER);
	 ob->set_name("lizard-man");
	 ob->set_al(-40+random(82));
	 ob->set_short("lizard-man");
	 ob->set_race("lizard-man");
	 ob->set_class("lizard-man");
	 ob->set_level(2+random(2));
	 ob->set_wimpy(0);
	 ob->add_alias("lizard");
	 ob->set_long("This is a vicious and fearsome lizard-man. "+
		"It has a mighty tail and sharp teeth.\n");
	 ob->add_property("monster_type", type);
	 ob->join_fights("A lizard-man enters the combat-fray.\n");
	 return ob;
	case "toad":
	 ob = clone_object(MONSTER);
	 ob->set_name("toad");
	 ob->add_adjective("ugly");
	 ob->set_race("reptile");
	 ob->set_al(-60);
	 ob->set_aggressive(1);
	 ob->set_level(1+random(2));
	 ob->set_short("giant toad");
	 ob->set_main_plural("giant toads");
	 ob->add_plural("toads");
	 ob->join_fights("A giant toad joins the fight.\n");
	 ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
	 ob->set_long("It's a a giant aggressive toad.\n");
	 ob->load_a_chat(30,
	 ({
		1, ":slaps you with its tongue."
	 }));
	 ob->add_property("monster_type", type);
	 return ob;
	case "muck-dweller":
	 ob = clone_object(MONSTER);
	 ob->set_name("muck-dweller");
	 ob->add_adjective("dirty");
	 ob->set_race("monster");
	 ob->set_al(-20);
	 ob->set_short("muck-dweller");
	 ob->set_level(1+random(2));
	ob->set_long("A dirty muck-dweller. It looks only vaguely humanoid.\n");
	ob->add_property("monster_type", type);
	return ob;
      case "lizard":
       ob = clone_object(MONSTER);
       ob->set_name("lizard");
       ob->set_short("giant lizard");
       ob->set_race("lizard");
       ob->set_level(3+random(5));
       ob->set_wimpy(0);
       ob->add_alias("reptile");
       ob->add_adjective("giant");
       ob->add_adjective("green");
       ob->set_long("The giant lizard looks hungry. It has green scales.\n");
       ob->load_chat(5,({1, ":crawls around.\n"}));
       ob->load_a_chat(50,({1, ":bashes you with its tail.\n"}));
       ob->add_property("monster_type", type);
       ob->join_fights("A lizard smells the blood of the fight and attacks.\n");
       ob->load_chat(10,
	 ({
		1, "'Grrrrrr!",
		1, ":bares it's teeth.",
		1, ":growls menacingly.",
	 }));
	 return ob;
      case "snake":
	 ob = clone_object(MONSTER);
	 ob->set_name("snake");
	 ob->set_short("snake");
	 ob->set_al(-30);
	 ob->set_main_plural("snakes");
	 ob->add_alias("worm");
	 ob->set_race("snake");
	 ob->set_level(2+random(2));
	 set_long("This is an agressive large snake.\n");
	 ob->set_aggressive(1);
	 ob->join_fights("A snake slithers into the fight.\n");
	 ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
	 ob->add_triggered_action("regen", "death", HOSPITAL, "regen_after_death");
	 ob->add_property("monster_type", type);
	 return ob;
	case "ceratosaur":
	 ob = clone_object(MONSTER);
	 ob->set_name("ceratosaur");
	 ob->add_alias("dinosaur");
	 ob->add_adjective("feroscious");
	 ob->set_al(-20+random(21));
	 ob->set_race("monster");
	 ob->set_level(8+random(4));
	 ob->set_wimpy(0);
	 ob->set_short("ceratosaur");
	 ob->set_plural("ceratosaurs");
	 set_long("This is ferocious Ceratosaur. It's a swamp-dinosaur.\n");
	 ob->load_chat(5,({ 1, ":roars loudly." }));
	 ob->load_a_chat(20,
	 ({
		1, ":roars loudly.",
		1, ":lashes out with its tail.",
	 }));
	 ob->add_property("monster_type", type);
	 return ob;
	case "bullywug":
	 ob = clone_object(MONSTER);
	 ob->set_name("bullywug");
	 ob->add_adjective("frog");
	 ob->set_race("bullywug");
	 ob->set_level(3+random(2));
	 ob->set_al(-50);
	 ob->set_long("The bullywug is a bipedal frog-like amphibian. "+
		"It has a smooth, mottled olive-green hide.\n");
	 ob->set_main_plural("bullywugs");
	 ob->set_short("bullywug");
	 ob->load_chat(7,
	 ({
		1, "'Crrrk crrrroa grrrrk.",
		1, "'Hrrrl chrrrra!",
		1, "'Grub uurch chrh srrckur!",
		1, ":gives a sign with his tongue towards the bushes.",
		1, "@drool $lname$",
	 }));
	 ob->load_a_chat(20,
	 ({
		1, "'Croooack croooack!",
		1, "'Crrrc!",
		1, ":croaks.",
	 }));
	 ob->add_move_zone("barracks");
	 ob->add_property("monster_type", type);
	 ARMORY->request_weapon("bastard_sword",50+random(70))->move(ob);
	 ARMORY->request_armour("leather",60+random(40))->move(ob);
	 ob->join_fights("A bullywug happily exclaims: Cooooorak!.\n");
	 ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
	 ob->init_equip();
	 return ob;
	case "hunter":
	 ob = clone_object(MONSTER);
	 ob->set_name("hunter");
	 ob->set_short("hunter");
	 ob->add_adjective("swamp");
	 ob->set_main_plural("hunters");
	 ob->set_long("Just a swamp hunter.\n");
	 ob->set_race("half-orc");
	 ob->set_class("fighter");
	 ob->set_level(random(10));
	 ob->set_wimpy(0);
	 ob->set_al(-100+random(201));
	 ob->adjust_money(random(70), "copper");
	 ob->load_chat(5,
	 ({
		1, "@search",
		1, "@grunt",
		1, "'These swamps are MY hunting grounds!",
		1, "'I hope you haven't come for a crocodile-hunt.",
		1, "'What are you doing here ?"
	 }));
	 ob->load_a_chat(30,
	 ({
		1, "'Get outta here!",
		1, "@spit $lname$",
		1, "'Ughh!",
		1, "@drool"
	 }));
	/* OKAY, COMMENTIGN OUT begins here, Fen   -CT.
	 if(random(2))
	ARMORY->request_armour("leather",40+random(40))->move(ob);
	 if(random(4))


	ARMORY->request_armour("soft leather cap", 70+random(30))->move(ob);
	 if(random(2))
	ARMORY->request_weapon("short_sword", 70+random(30))->move(ob);
	 ob->add_property("monster_type", type);
	 ob->init_equip();
	COMMENTING OUT ENDS HERE, Fen -CT  */
	 return ob;
	case "animal":
	 ob = clone_object(MONSTER);
	 ob->set_race("monster");
	 ob->set_long("It's just an animal.\n");
	 /* ob->set_wimpy(10); */
	 switch(random(6))
	 {
		case 0:
		 ob->set_name("dog");
		 ob->set_short("swamp dog");
		 ob->add_adjective("swamp");
		 ob->set_main_plural("dogs");
		 ob->set_gender(0);
		 ob->set_level(-1+random(2));
		 break;
		case 1:
		 ob->set_name("boar");
		 ob->set_short("wild boar");
		 ob->add_adjective("wild");
		 ob->set_main_plural("boars");
		 ob->set_gender(0);
		 ob->set_level(1+random(2));
		 break;
		case 2:
		 ob->set_name("toad");
		 ob->set_short("green toad");
		 ob->add_adjective("green");
		 ob->set_main_plural("deer");
		 ob->set_gender(0);
		 ob->set_level(-1+random(2));
		 break;
		case 3:
		 ob->set_name("crawler");
		 ob->set_short("carrion crawler");
		 ob->add_adjective("carrion");
		 ob->set_main_plural("carrion crawlers");
		 ob->set_gender(0);
		 ob->set_level(random(3));
		 break;
		case 4:
		 ob->set_name("lamprey");
		 ob->set_short("land lamprey");
		 ob->set_long("It looks like a leech ending in a row of teeth.\n");
		 ob->add_adjective("land");
		 ob->set_main_plural("land lampreys");
		 ob->set_gender(0);
		 ob->set_level(1+random(3));
		 break;
		case 5:
		 ob->set_name("leech");
		 ob->set_short("giant leech");
		 ob->add_adjective("giant");
		 ob->set_main_plural("giant leeches");
		 ob->set_gender(0);
		 ob->set_level(2);
		 break;
	 }
	 ob->add_property("monster_type", type);
	 return ob;
	case "hermit":
	 ob = clone_object(MONSTER);
	 ob->set_name("hermit");
	 ob->set_race("human");
	 ob->set_level(1+random(8));
         ob->set_wimpy(0);
	 ob->add_alias("man");
	 ob->set_al(10);
	 /* ob->set_wimpy(10); */
         ob->add_move_zone("forest");
         ob->add_move_zone("plains");
	 ob->adjust_money(random(100),"copper");
	 ob->set_short("hermit");
	 ob->set_long("This is one of the loners who wanders the "+
		"Forgotten Realms.\n");
	 ob->add_property("monster_type", type);
	 return ob;
	case "catoblepas":
	 ob = clone_object(MONSTER);
	 ob->set_name("catoblepas");
	 ob->add_adjective("large");
	 ob->set_race("monster");
	 ob->set_class("fighter");
	 ob->set_al(-200);
	 ob->set_level(7+random(6));
	 ob->set_wimpy(0);
	 ob->set_short("a catoblepas");
	 ob->set_main_plural("catoblepases");
	 ob->join_fights("Hearing sounds the catoblepas "+
		"lumbers into the fray.\n");
	 ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
	 ob->set_long("The catoblepas walks with it's head raking the ground, "+
	  "so it probably can't see you with all the vegetation here. This is "+
	  "a good thing, for rumor goes it can kill you simply by looking at "+
	  "you. If you attack it just might raise its head.\n");
	 ob->load_chat(5,
	 ({
	  1, ":raises its head slightly, but the neck is luckily to weak.",
	  1, ":walks around with its head held low.",
	 }));
	 ob->load_a_chat(30,
	 ({
	  1, ":strikes you with its tail.",
	  1, ":raises its head slightly trying to get a glimpse of you.",
	 }));
	 ob->add_property("monster_type", type);
         // ob->add_attack("gaze", 0 , 1, 3000, 0, 0, "magic");
	 return ob;
	case "cantobele":
	 ob = clone_object(MONSTER);
	 ob->set_name("cantobele");
	 ob->add_adjective("fast");
	 ob->set_race("monster");
	 ob->set_al(-20);
	 ob->set_short("cantobele");
         ob->set_main_plural("contobeles");
	 ob->set_level(3+random(4));
	 ob->set_wimpy(0);
	 ob->set_long("The cantobele is a fast, six-legged, lion-like creature.\n");
	 ob->add_property("monster_type", type);
         for(i = 0; i < 8; i++)
          // ob->add_attack("claw"+i, 0, 80, 80, 0, 0, "sharp-claw");
	 return ob;
        default:
          ob = clone_object(MONSTER);
          ob->set_name("failure");
          ob->set_short("failure");
          ob->set_long(file_name(previous_object()));
          ob->set_level(1);
          return ob;
	}
}

void regen_after_death()
{
	object ob, dest;
	string nam;

	nam = (string)previous_object()->query_property("monster_type");
	dest = (object)previous_object()->query_property("start location");
	if (!dest)
		return ;
	ob = get_monster(nam);
	dest->add_monster(previous_object(), ob);
	call_out("do_move", 10, ({ ob, dest }) );
}

void do_move(mixed *junk)
{
 if(junk[0])
   junk[0]->move(junk[1]);
}

void death()
{
	call_out("do_pick_up", 0, previous_object());
}

void do_pick_up(object ob)
{
	ob->init_command(":loots the corpse.\n");
	ob->init_command("get all from corpses");
	ob->run_away();
}







