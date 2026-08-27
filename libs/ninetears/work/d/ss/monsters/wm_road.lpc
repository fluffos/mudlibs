#define MONSTER "obj/monster"
#define ARMORY "obj/handlers/armoury"
#define HOSPITAL "/d/ss/monsters/wm_road"

inherit "std/room";

int *road_chance, road_tot_chance, i;
string *road_monsters;


object get_monster(string type)
{
   object ob, ob2;
   int temp, rand, loop;
   
   if(!road_monsters)
      {
      road_monsters =
      ({
            "bandit", "mercenary", "bear", "orc", "wanderer",
            "minotaur", "wizard", "warrior", "orog", "goblin",
            "gnoll", "animal"
       });
   }
   if(!road_chance)
      {
      road_chance =
      ({
            11, 10, 5, 10, 5,
            3, 1, 10, 5, 5,
            5, 30
       });
      road_tot_chance = 100;
   }
   switch(type)
   {
    case "road":
      rand = random(road_tot_chance - road_chance[sizeof(road_chance) - 1]);
      temp = 0;
      loop = 0;
      while(rand > temp)
      temp += road_chance[loop++];
      ob2 = get_monster(road_monsters[loop]);
      ob2->add_move_zone("road");
      ob2->add_property("monster_type", type);
      return ob2;
    case "wizard":
      i = random(13);
      ob = clone_object(MONSTER);
      ob->set_name("magician");
      ob->add_alias("wizard");
      ob->set_short("wandering magician");
      ob->set_main_plural("magicians");
      ob->set_race("human");
      ob->set_al(-100+random(201));
      ob->set_class("wizard");
      ob->set_level(i);
      ob->set_wimpy(0);
      ob->add_move_zone("city");
      // ob->add_attack("spell", 0, 80, i*10, 30, 0, "magic");
      ob->set_max_hp(7+i*6);
	/* COMMENTING OUT NEXT LINE, Fen   -CT
      ARMORY->request_armour("cloth robe",40+random(20))->move(ob);
	COMMENTING ENDS HERE, Fen  -CT */
      ob->set_long("He looks like a Magician at least. Who else would wear "+
         "such a long robe and have a long white beard ?\n");
      ob->adjust_money(({random(i*5), "copper", random(i), "silver"}));
      ob->load_chat(2,
         ({
               1, "The wizard shuffles away from you.",
               1, "'Hmmm... How did that fireball-spell go again ?",
               1, "'What did you say ?",
               1, "'Ylle bulle srchraff graff hrrrla hrrril sprrt.",
               1, "@sigh",
          }));
      ob->load_a_chat(20,
         ({
               1, "'Die feeble mortal.",
               1, "'Do you know the powers you are messing with.",
               1, ":mutters some strange incantation.",
               1, ":readies some cat-whiskers and a piece of a dragon's claw."+
               "Oh, don't worry, it's probably just for casting some spell.",
               1, ":misses you with a spell, destroying a tree instead."
          }));
      ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
      ob->add_property("monster_type", type);
      ob->init_equip();
      return ob;
    case "orog":
      ob = clone_object(MONSTER);
      ob->set_name("orog");
      ob->add_adjective("big");
      ob->add_adjective("ugly");
      ob->set_short("orog");
      ob->set_al(70);
      ob->set_main_plural("orogs");
      ob->add_move_zone("castle");
      ob->add_move_zone("forest");
      ob->set_long("Ugly big orclike creature.\n");
      ob->set_aggressive(1);
      ob->adjust_money(random(30),"copper");
      ob->join_fights("An orog gleefully throws itself into combat.\n");
      ob->set_race("orc");
      ob->set_level(2+random(3));
      ob->set_wimpy(0);
      ob->load_chat(2,
         ({
               1, "'Kloss-lunk argchr ?",
               1, "@grin evilly at $lname$",
          }));
      ob->load_a_chat(30,
         ({
               1, "'KLOSS-LUNK, KLOSS-LUNK!",
               1, "'Grrrrrrrr!!!",
               1, ":licks blood off his chin."
          }));
      ob->add_property("monster_type", type);
	/* COMMENTING OUT NEXT LINE, -CT
      ARMORY->request_armour("leather",80+random(20))->move(ob);
	COMMENTING ENDS HERE    -CT */
      ob->init_equip();
      return ob;
    case "goblin":
      ob = clone_object(MONSTER);
      ob->set_name("goblin");
      ob->add_adjective("ugly");
      ob->add_adjective("little");
      ob->set_al(30);
      ob->set_short("goblin");
      ob->set_main_plural("goblins");
      ob->add_move_zone("castle");
      ob->add_move_zone("forest");
      ob->set_long("Just an ugly little humanoid.\n");
      ob->set_aggressive(1);
      ob->adjust_money(random(10),"copper");
      ob->join_fights("A goblin gleefully throws itself into combat.\n");
      ob->set_race("goblin");
      ob->set_level(-2+random(4));
      ob->set_wimpy(0);
      ob->load_chat(2,
         ({
               1, "'Bree-yark argchr ?",
               1, "@grin evilly at $lname$",
          }));
      ob->load_a_chat(30,
         ({
               1, "'BREE-YARK, BREE-YARK!",
               1, "'Grrrrrrrr!!!",
               1, ":tries to bite you."
          }));
	/* COMMENTING OUT BEGINS HERE   -CT
      ob->add_property("monster_type", type);
      ARMORY->request_weapon("dagger",50+random(20))->move(ob);
      if(random(2))
         ARMORY->request_armour("leather",50+random(20))->move(ob);
      ob->init_equip();
	COMMENTING OUT ENDS HERE   -CT */
      return ob;
    case "bandit":
      ob = clone_object(MONSTER);
      ob->set_name("bandit");
      ob->add_alias("road-bandit");
      ob->set_al(40);
      ob->set_short("bandit");
      ob->set_race("human");
      ob->set_level(3+random(2));
      ob->set_wimpy(0);
      ob->add_alias("robber");
      ob->set_long("This is a vicious and ammoral road-bandit. "+
         "He's probably here to rob you.\n");
      ob->adjust_money(10+random(20),"copper");
      ob->load_chat(5,
         ({
               1, "'Your money or your valueless life please.",
               1, ":moves over to you and demands to have all your money.",
          }));
      ob->load_a_chat(30,
         ({
               1, "'Don't you dare have no money in your corpse!",
               1, "'Gimme your money, and I'll let you live.",
               1, "'Taste THIS!",
               1, "'Ouch!",
               1, "@grin wickedly $lname$",
          }));
	/* MORE COMMENTING FEN   -CT
      if(random(4))
         ARMORY->request_weapon("long sword",70+random(30))->move(ob);
      else
         ARMORY->request_weapon("short sword",50+random(30))->move(ob);
      ARMORY->request_armour("leather",60+random(40))->move(ob);
	COMMENTING STOPS HERE   -CT */
      ob->add_property("monster_type", type);
      ob->join_fights("A bandit enters the combat-fray.\n");
      ob->init_equip();
      return ob;
    case "gnoll":
      ob = clone_object(MONSTER);
      ob->set_name("gnoll");
      ob->add_adjective("ugly");
      ob->set_race("monster");
      ob->set_al(60);
      ob->set_aggressive(1);
      ob->set_level(1+random(2));
      ob->set_wimpy(0);
      ob->set_short("ugly gnoll");
      ob->set_main_plural("ugly gnolls");
      ob->add_plural("gnolls");
      ob->join_fights("An ugly gnoll joins the fight.\n");
      ob->set_long("It's a large hyena-like humanoid.\n");
      ob->load_chat(5,
         ({
               1, ":stares at you in a hostile way.\n",
               1, "'Arrrl urrr marrch errremiii!\n"
          }));
      ob->load_a_chat(30,
         ({
               1, "'Urrrrl DIE!\n",
               1, "'Urrrrl i hrrch ngice hrrrrohi.\n",
               1, "'Grrrrrr!\n"
          }));
	/* HEH.. MORE COMMENTING, FEN  -CT
      if(random(2))
         ARMORY->request_weapon("club",40+random(40))->move(ob);
      else
         ARMORY->request_weapon("battle_axe",40+random(90))->move(ob);
      ARMORY->request_armour("leather",40+random(40))->move(ob);
	STOPPED COMMENTING HERE   -CT */
      ob->add_property("monster_type", type);
      ob->init_equip();
      return ob;
    case "mercenary":
      ob = clone_object(MONSTER);
      ob->set_name("mercenary");
      ob->add_adjective("tough");
      ob->set_race("human");
      ob->set_al(-90+random(161));
      ob->set_short("mercenary");
      ob->set_level(4+random(8));
      ob->set_wimpy(0);
      ob->set_long(
         "A tough battled scarred mercenary.  There are better ways of filling in " +
         "an afternoon than messing with the likes of him.\n");
      ob->adjust_money(({random(10),"silver", random(100), "copper"}));
      ob->load_chat(3,
         ({
               1, "'Anyone you don't like?\n",
               1, "'I'll do anything if the price is right?\n",
               1, "'Don't get me angry.  You won't like me when I'm angry.\n"
          }));
      ob->load_a_chat(30,
         ({
               1, "'I'll show you whose boss\n",
               1, "'You think you're so tough\n",
               1, "'Finally a fight. Pity it's my day off though.\n"
          }));
	/* SIGH, MORE COMEMTNING....   -CT
      if(random(2))
         ARMORY->request_weapon("bastard sword", 40+random(60))->move(ob);
      else
         ARMORY->request_weapon("long sword", 40+random(60))->move(ob);
      ARMORY->request_armour("chainmail", 40+random(60))->move(ob);
	COMMENTING ENDS -CT */
      ob->add_property("monster_type", type);
      ob->init_equip();
      return ob;
    case "bear":
      ob = clone_object(MONSTER);
      ob->set_name("bear");
      ob->set_short("bear");
      ob->set_race("monster");
      ob->set_level(2+random(2));
      ob->set_wimpy(0);
      ob->add_alias("brown bear");
      ob->add_adjective("large");
      ob->add_adjective("brown");
      ob->set_long(
         "This is a large brown bear. It seems quite hungry.\n");
      ob->load_chat(5,({1, "The bear raise up on it's hind legs.\n"}));
      ob->load_a_chat(50,({1, "The bear roars.\n"}));
      ob->add_property("monster_type", type);
      ob->join_fights("A bear smells the blood of the fight and attacks.\n");
      ob->add_move_zone("forest");
      ob->load_chat(10,
         ({
               1, "@growl",
               1, ":bares it's teeth.",
               1, ":stalks you.",
               1, "@growl nastily $lname$",
          }));
      return ob;
    case "orc":
      ob = clone_object(MONSTER);
      ob->set_name("orc");
      ob->set_short("orc");
      ob->set_al(60);
      ob->set_main_plural("orcs");
      ob->add_alias("monster");
      ob->set_race("orc");
      ob->set_level(1+random(2));
      ob->set_wimpy(0);
      set_long("This is an orc, an aggressive mammalian carnivore.\n");
      ob->adjust_money(random(300), "copper");
      ob->set_aggressive(1);
      ob->load_a_chat(10,
         ({
               1, "'Eh humin! Niis itin!",
               1, "@growl",
               1, "@grin evilly $lname$",
               1, ":pokes it's teeth.",
               1, "@growls nastily $lname$",
               1, ":looks at you with big red eyes.",
          }));
      ob->join_fights("An orc joins the fight.\n");
      ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
      ob->add_triggered_action("regen", "death", HOSPITAL, "regen_after_death");
      ob->add_property("monster_type", type);
      ob->load_a_chat(50,({1, "'Grrtl hraack khrallunck."}));
      return ob;
    case "wanderer":
      ob = clone_object(MONSTER);
      ob->set_name("wanderer");
      ob->add_alias("wandering man");
      ob->add_alias("tourist");
      ob->set_al(-20+random(60));
      ob->set_race("human");
      ob->set_level(1+random(4));
      ob->set_short("wanderer");
      ob->set_plural("wanderers");
      ob->add_move_zone("forest");
      ob->add_move_zone("castle");
      ob->add_move_zone("city");
      set_long("This is a wanderer from some distant country.\n"+
         "He's busy acting like a tourist (gawking).\n");
      ob->adjust_money(random(10), "copper");
      ob->load_chat(5,
         ({
               1, "'Hvor er severdighetene her ?",
               1, "'Unnskyld, snakker De norsk ?",
               1, "'Vet du om de har Ringnes i pubene her ?",
               1, ":gawks around.",
               1, "@smile winningly $lname$",
               1, "@jump",
               1, "@stare $lname$",
               1, "@gaze adm $lname$",
          }));
      ob->load_a_chat(20,
         ({
               1, "'Drittsekk!! Ligg unna!",
               1, "'UTLENDINGER, alltid skal dere sloss!",
               1, "'Slapp av litt da, din dritt!",
               1, ":starts to concentrate on the fighting instead of gawking.",
               1, "@gaze with wide innocent eyes $lname$",
          }));
	/* ONE LINE COMMENT OUT. -CT
      ARMORY->request_weapon("dagger",20+random(40))->move(ob);
	END ONE LINE COMMENT -CT */
      ob->add_property("monster_type", type);
      ob->init_equip();
      return ob;
    case "minotaur":
      ob = clone_object(MONSTER);
      ob->set_name("minotaur");
      ob->add_adjective("brutal");
      ob->add_adjective("big");
      ob->set_race("troll");
      ob->set_level(7+random(6));
      ob->set_wimpy(0);
      ob->set_al(50);
      ob->set_short("big minotaur");
      ob->set_main_plural("big minotaurs");
      ob->set_long(
         "This is a big ox-like humanoid.  It seems that it wants to " +
         "challenge you to a fight.  It looks incredibly brutal however, " +
         "so you might be better off swallowing your pride and bother " +
         "somebody else.\n");
      ob->load_chat(7,
         ({
               1, "'Ghutt upp wuppun, un fuut.",
               1, "'Luttschee huw good yuu arch in cumbutt.",
               1, "'Grub uurch archmch and fuut, suckur!",
               1, ":twirls it's axe.",
               1, ":roars a challenge to $lname$",
          }));
      ob->load_a_chat(20,
         ({
               1, "'Funnnulii a fuut!",
               1, "'Juur bruuv!",
               1, "'Juur suun dudd! HU!",
          }));
      ob->add_move_zone("forest");
      ob->add_move_zone("plains");
      ob->add_property("monster_type", type);
	/* Another ONE LINE COMMENT OUT   -CT
      ARMORY->request_weapon("battle_axe",50+random(70))->move(ob);
	YUP... COMMENTING ENDS HERE   -CT */
      ob->join_fights("A minotaur happily exclaims: A FUUT!.\n");
      ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
      ob->init_equip();
      return ob;
    case "warrior":
      ob = clone_object(MONSTER);
      ob->set_name("warrior");
      ob->set_short("warrior");
      ob->set_main_plural("warriors");
      ob->set_long("Just a wandering warrior.\n");
      ob->set_race("half-orc");
      ob->set_level(random(11));
      ob->set_wimpy(0);
      ob->set_al(-100+random(201));
      ob->adjust_money(100+random(400), "copper");
      ob->load_chat(5,
         ({
               1, "@spit $hcname$",
               1, "@grunt",
               1, "'Are you trying to provoke me ?",
               1, "'Are you a spell-caster ?  I just love thrashing those!",
               1, "'Go suck yourself, wimp!"
          }));
      ob->load_a_chat(30,
         ({
               1, "'YOU'RE GONNA DIE FOR THIS.",
               1, "'Let's see who's boss here $acname$",
               1, "'Ughh!",
               1, "'Don't you dare leave in the middle of my fight!"
          }));
      ob->add_move_zone("castle");
      ob->add_move_zone("city");
      ob->add_move_zone("plains");
	/* DAMN... MORE COMMENTING... -CT
      if(random(2))
         ARMORY->request_armour("chainmail",90+random(90))->move(ob);
      else 
         ARMORY->request_armour("ring mail", 70+random(50))->move(ob);
      ARMORY->request_weapon("bastard sword", 70+random(30))->move(ob);
	GRR... YA KNOW IT ENDS HERE   -CT */
      ob->add_property("monster_type", type);
      ob->init_equip();
      return ob;
    case "animal":
      ob = clone_object(MONSTER);
      ob->set_race("monster");
      ob->set_long("It's just an animal.\n");
      switch(random(6))
      {
        case 0:
         ob->set_name("dog");
         ob->add_alias("dog");
         ob->set_main_plural("dogs");
         ob->set_gender(0);
         ob->set_level(-1+random(2));
         break;
        case 1:
         ob->set_name("boar");
         ob->add_alias("boar");
         ob->set_main_plural("boars");
         ob->set_gender(0);
         ob->set_level(1+random(1));
         break;
        case 2:
         ob->set_name("deer");
         ob->set_short("deer");
         ob->add_alias("deer");
         ob->set_main_plural("deer");
         ob->set_gender(0);
         ob->set_level(-1+random(2));
         break;
        case 3:
         ob->set_name("rabbit");
         ob->set_short("a rabbit");
         ob->add_alias("rabbit");
         ob->set_main_plural("rabbit");
         ob->set_gender(0);
         ob->set_level(-2+random(2));
         break;
        case 4:
         ob->set_name("wasps");
         ob->set_short("swarm of wasps");
         ob->set_long("The swarm contains an enormous amount of insects.\n");
         ob->add_alias("swarm");
         ob->set_main_plural("wasp swarms");
         ob->set_gender(0);
         ob->set_level(1+random(3));
         ob->set_max_hp(60);
         break;
        case 5:
         ob->set_name("ox");
         ob->set_short("ox");
         ob->add_alias("ox");
         ob->set_main_plural("oxes");
         ob->set_gender(0);
         ob->set_level(3+random(1));
         break;
         }
      ob->set_wimpy(0);
      ob->add_property("monster_type", type);
      ob->add_move_zone("forest");
      return ob;
     case "trader":
      ob = clone_object(MONSTER);
      ob->set_name("trader");
      ob->set_race("human");
      ob->set_level(1+random(5));
      ob->add_alias("man");
      ob->set_al(10);
      ob->set_wimpy(10); 
      ob->adjust_money(random(30),"copper");
      ob->set_short("hermit");
      ob->set_long("This is one of the traders who wander the roads of the "+
         "Forgotten Realms.\n");
      ob->add_property("monster_type", type);
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
   ob->do_command(":loots the corpse.\n");
   ob->do_command("get all from corpses");
   ob->run_away();
}
