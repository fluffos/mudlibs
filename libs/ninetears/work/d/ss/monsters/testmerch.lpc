#define MONSTER "/obj/monster"
#define ARMORY "/obj/handlers/armoury"
#define HOSPITAL "/d/ss/monsters/hospital"

inherit "std/room";

int *city_chance, city_tot_chance, i;
string *city_monsters;


object get_monster(string type) {
  object ob, ob2;
  int temp, rand, loop;

  if(!city_monsters) {
    city_monsters = ({
      "merchant", "mercenary", "rat", "beggar", "sailor",
      "officer", "wizard", "merchant", "warrior", "thief",
      "assassin", "person" });
  }
  if(!city_chance) {
    city_chance = ({
      1, 1, 5, 20, 5,
      3, 10, 10, 20, 5,
      5, 15 });
    city_tot_chance = 100;
  }
  switch(type) {
    case "city":
      rand = random(city_tot_chance - city_chance[sizeof(city_chance) - 1]);
      temp = 0;
      loop = 0;
      while(rand > temp)
        temp += city_chance[loop++];
      ob2 = get_monster(city_monsters[loop]);
      ob2->add_move_zone("city");
      ob2->add_property("monster_type", type);
      return ob2;
    case "wizard":
      ob = clone_object(MONSTER);
      i = 5+random(8);
      ob->set_name("wizard");
      ob->add_alias("magician");
      ob->set_short("Wizard");
      ob->set_main_plural("wizards");
      ob->set_race("human");
      ob->set_class("wizard");
      ob->set_level(i);
      ob->add_move_zone("pub");
      ob->set_long(
"This is a wizard of the Wizards Guild.  He is a powerful wizard "+
"by the looks of his uniform.  You'd best leave him alone.\n");
      ob->adjust_money(random(i*4), "copper");
      ob->load_chat(2, ({
        1, ":shuffles away from you.\n",
        1, "'Not now please, I'm very busy.\n",
        1, "'What did you say?\n",
        1, "'Have you seen a pipe?  One of the senior wizards " +
        "has lost his.\n",
        1, "@sigh",
      })); 
      ob->load_a_chat(20, ({
        1, "'Die feeble mortal.",
        1, "'Do you know the powers you are messing with.",
        1, ":mutters some strange incantation.",
        1, "The crowd flee in terror.",
        1, ":misses you and a spectator vanishes."
      }));
      ob->set_weap_skill("magic");
      // ob->add_attack("spell", 0, 20, random(i*10), 100, 0, "magic");
      ob->add_move_zone("tavern");
      ob->add_property("monster_type", type);
      ob->set_max_hp(450+10*i);
      return ob;
    case "thief":
      ob = clone_object(MONSTER);
      ob->set_name("thief");
      ob->set_short("thief");
      ob->set_main_plural("thieves");
      ob->add_move_zone("pub");
      ob->set_long(
"This is a member of the thieves guild.  You better be careful.  "+
"He probably has lots of friends.\n");
      ob->adjust_money(1+random(10),"copper");
      ob->add_triggered_action("bing", "pub_brawl", HOSPITAL, "pub_brawl");
      ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
      ob->set_race("human");
      ob->set_level(1+random(5));
       ob->set_class("thief");
      ob->load_chat(2, ({
        1, "'Have you paid all your robbery tax this year ?\n",
        1, ":seems to have fallen in love with the sight of your wallet.\n",
        1, ":wanders over to someone and threatens them.\n",
        1, "@peer sus at $lname$",
      }));
      ob->load_a_chat(30, ({
        1, "'Wait till my boss hears about this!",
        1, "'There's someone behind you!",
        1, "'If you leave now, I might forget this incident.",
        1, ":tries to hide in the crowd, but fails."
      }));
      ob->add_property("monster_type", type);
      ARMORY->request_weapon("dagger",80+random(20))->move(ob);
      ARMORY->request_armour("leather",80+random(20))->move(ob);
ob->init_equip();
      return ob;
    case "merchant":
      ob = clone_object(MONSTER);
      ob->set_name("merchant");
      ob->set_short("Merchant");
      ob->set_race("human");
      ob->set_class("merchant");
      ob->set_level(4+random(3));
      ob->add_alias("trader");
      ob->set_long(
"This is a merchant. He comes to Daggerford to sell his goods.\n");
      ob->adjust_money(random(20),"copper");
      ob->load_chat(5, ({
        1, "'My goods are cheapest.",
        1, "'Don't buy his, they are defective.",
        1, "'Alas, It'll be the death of me, but you can have it cheap.",
        1, "'What?  No you can't possibly have it cheaper.",
        1, ":shuffles over to you and mutters about what he is selling.",
        1, ":wanders over to an unsuspecting victim and tries to " +
           "sell to him."
      }));
      ob->load_a_chat(60, ({
        1, "'But I paid the thieves guild already.",
        1, "'The lords will hear about this.",
        1, "'Why me ?",
        1, "'Help, Cityguards save me.",
        1, ":tries to bribe you to leave."
      }));
      if(random(4))
        ARMORY->request_weapon("knife",40+random(40))->move(ob);
      ARMORY->request_armour("cape",40+random(40))->move(ob);
      ob->add_property("monster_type", type);
ob->init_equip();
      return ob;
    case "assassin":
      ob = clone_object(MONSTER);
      ob->set_name("mercenary");
      ob->add_adjective("mean");
      ob->set_race("human");
      ob->set_class("assassin");
      ob->set_level(6+random(6));
      ob->set_short("Mean Mercenary");
      ob->set_main_plural("mean mercenaries");
      ob->add_plural("mercenaries");
      ob->add_triggered_action("bing", "pub_brawl", HOSPITAL, "pub_brawl");
      ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
      ob->set_long(
"This is a mean mercenary.  He is wearing a stylish robe.  From his "+
"looks you get the impression he is not going to like being bothered.\n");
      ob->load_chat(5, ({
        1, ":stares at you in a strange way.",
        1, ":seems to be watching you."
      }) );
      ob->load_a_chat(30, ({
        1, "'you'll be sorry for this.",
        1, "'Just wait till I tell Angelica.",
        1, "'Ouch!"
      }) );
      if(random(2))
        ARMORY->request_weapon("dagger",60+random(40))->move(ob);
      ARMORY->request_armour("cape", 90+random(10))->move(ob);
      ob->add_property("monster_type", type);
ob->init_equip();
      return ob;
    case "mercenary":
      ob = clone_object(MONSTER);
      ob->set_name("mercenary");
      ob->add_adjective("tough");
      ob->set_race("human");
      ob->set_class("fighter");
      ob->set_level(13);
      ob->add_triggered_action("bing", "pub_brawl", HOSPITAL, "pub_brawl");
      ob->set_long(
"A tough battled scarred mercenary.  There are better ways of filling in " +
"an afternoon that messing with the likes of him.\n");
      ob->adjust_money(100 + random(100), "copper");
      ob->load_chat(3, ({
        1, "'Anyone you don't like ?",
        1, "'I'll do anything if the price is right?",
        1, "'Don't get me angry.  You won't like me when I'm angry."
      }));
      ob->load_a_chat(30, ({
        1, "'I'll show you who's boss.",
        1, "'You think your so tough!",
        1, "The crowd run in terror as the Mercenary swing wildly around "+    
           "himself."
      }));
      if(random(10))
        ARMORY->request_weapon("dagger", 40+random(60))->move(ob);
      else
        ARMORY->request_weapon("dagger", 40+random(60))->move(ob);
      ARMORY->request_armour("chainmail", 40+random(60))->move(ob);
      ob->add_property("monster_type", type);
ob->init_equip();
      return ob;
    case "rat":
      ob = clone_object(MONSTER);
      ob->set_name("rat");
      ob->set_short("rat");
      ob->set_race("rat");
      ob->set_level(-5);
      ob->add_alias("city rat");
      ob->add_adjective("dirty");
      ob->add_adjective("city");
      ob->set_long(
"This is a large rat.  It appears to have done well living in the city.\n"+
"The pollution must not affect it to much.\n");
      ob->load_chat(5,({1, "The rat squeaks.\n"}));
      ob->load_a_chat(50,({1, "The rat squeels in pain.\n"}));
      ob->add_triggered_action("regen", "death", HOSPITAL, "regen_after_death");
      ob->add_property("monster_type", type);
      return ob;
    case "beggar":
      ob = clone_object(MONSTER);
      ob->set_name("beggar");
      ob->set_short("Poor beggar");
      ob->set_main_plural("Poor Beggars");
      ob->add_alias("beggar");
      ob->set_race("human");
      ob->set_level(-3+random(3));
      set_long(
"This is a poor beggar.  Perhaps you should give him some money.\n");
      ob->adjust_money(random(100), "copper");
      ob->load_chat(10, ({
1, "'Money for the poor.",
1, "'Please give me some money.",
1, ":pulls on your leg.",
1, ":rattles his tin.",
1, ":mutters something about a wife and 7 children.",
1, ":looks at you with big brown eyes.",
1, "'who will help me ?",
1, ":looks down at the ground and sobs."
      }));
      ob->add_property("monster_type", type);
      return ob;
    case "sailor":
      ob = clone_object(MONSTER);
      ob->set_name("sailor");
      ob->add_alias("seaman");
      ob->add_adjective("drunken");
      ob->set_race("human");
      ob->set_level(1+random(5));
      ob->set_short("Sailor");
      ob->add_move_zone("pub");
      ob->add_triggered_action("bing", "pub_brawl", HOSPITAL, "pub_brawl");
      set_long(
"This is a sailor from one of the many countries that trade here.\n"+
"He is roaring drunk.\n");
      ob->adjust_money(random(10), "copper");
      ob->load_chat(5, ({
1, "'You aven't sh'een a pub go pash't ave you ?",
1, "'It wash' here a minute ago.",
1, "'Why are there two of you ?",
1, ":staggers backwards and forwards.",
1, "@burp",
1, "@trip",
1, "@puke",
      }));
      ob->load_a_chat(20, ({
1, "'What I do?, What I do ?",
1, "'Help me guysh!  He'sh picking on me.",
1, "'Boy are you in trroublesh now.",
1, ":swings his fists wildly.",
1, ":trips and runs into a post."}));
      ARMORY->request_weapon("dagger",20+random(80))->move(ob);
      ob->add_property("monster_type", type);
ob->init_equip();
      return ob;
    case "officer":
      ob = clone_object(MONSTER);
      ob->set_name("officer");
      ob->add_adjective("militia");
      ob->set_race("human");
      ob->set_class("fighter");
      ob->set_level(8+random(7));
      ob->set_short("Officer of the Militia");
      ob->set_main_plural("Officers of the Militia");
      ob->set_long(
"This is an Officer of the Militia. His job is to patrol Daggerford and "+
"keep it safe.\n");
      ob->load_chat(2, ({
1, "'Move along, Move along.",
1, "'Lets not be loitering then.",
1, "'You look suspicious.  Move on and I'll forget I saw you.",
1, ":twirls his batton.",
1, "@eye $lname$",
      }));
      ob->load_a_chat(20, ({
1, "'I'm sorry. You seem to be a honorable fellow after all.",
1, "'I'm prepared to forget this if you let me go.",
1, "'Mummy!",
1, "'Guards!!!!"
      }));
      ob->add_move_zone("barracks");
      ob->add_property("monster_type", type);
      ARMORY->request_weapon("long_sword",70+random(30))->move(ob);
      ARMORY->request_armour("leather",60+random(40))->move(ob);
ob->init_equip();
      return ob;
    case "warrior":
      ob = clone_object(MONSTER);
      ob->set_name("warrior");
      ob->set_short("Warrior");
      ob->set_main_plural("Warriors");
      ob->add_triggered_action("bing", "pub_brawl", HOSPITAL, "pub_brawl");
      ob->set_long(
"This is a warrior who is doing his hardest to make Daggerford a safe place "+
"to live.\n");
      ob->set_race("human");
      ob->set_class("fighter");
      ob->set_level(6+random(4));
      ob->adjust_money(random(30),"copper");
      ob->load_chat(5, ({ 1, ":grunts.\n",
      1, "@grunt",
      1, "'Are you trying to provoke me ?",
      1, "'What do you mean ?",
      1, "'Ug.\n"
      }));
      ob->load_a_chat(30, ({
      1, "'YOU'RE GONNA DIE FOR THIS.",
      1, "'Try to make the world a safe place and this happens.",
      1, "'Do you know who I am ?",
      1, "'Wulfgar the Barbarian is a close friend of mine you know."
      }));
      ob->add_move_zone("smithy");
      if(random(2))
        ARMORY->request_armour("cape",50+random(50))->move(ob);
      else
        ARMORY->request_armour("studded", 70+random(30))->move(ob);
      if(random(4))
        ARMORY->request_armour("cape",50+random(50))->move(ob);
      if(random(10))
        ARMORY->request_armour("cape", 70+random(30))->move(ob);
      if(random(2))
        ARMORY->request_weapon("dagger", 50+random(50))->move(ob);
      else
        ARMORY->request_weapon("knife", 70+random(30))->move(ob);
      ob->add_property("monster_type", type);
ob->init_equip();
      return ob;
    case "person":
      ob = clone_object(MONSTER);
      ob->set_race("human");
      ob->set_long("This is one of the inhabitants of Daggerford.\n");
      switch(random(3)) {
        case 0:
          ob->set_name("man");
          ob->add_alias("man");
          ob->set_main_plural("men");
          ob->set_gender(1);
          ob->set_level(-1+random(3));
          break;
        case 1:
          ob->set_name("lady");
          ob->add_alias("lady");
          ob->set_main_plural("ladies");
          ob->set_gender(2);
          ob->set_level(-1+random(3));
          break;
        case 2:
          ob->set_name("child");
          ob->set_short("child");
          ob->add_alias("child");
          ob->set_main_plural("children");
          ob->set_gender(1 + random(2));
          ob->set_level(-5+random(5));
      }
      ob->add_property("monster_type", type);
      return ob;
    case "garth":
      ob = clone_object(MONSTER);
      ob->set_name("garth");
      ob->set_race("human");
      ob->set_class("fighter");
      ob->set_level(14);
      ob->set_short("Garth the Pub-Brawler");
      ob->set_main_plural("Pub-Brawlers");
      ob->set_long(
"This is Garth the Pub-Brawler, renowned cutthroat and bad guy.  He hangs "+
"around in Lady Luck Tavern, just hoping for a fight. He'll be the first "+
"to join any fight that might start here.\n");
       ob->add_alias("cutthroat");
       ob->add_alias("pub-brawler");
       ob->adjust_money(random(100), "copper");
       ob->join_fights("Garth gleefully exclaims: PUB BRAWL!\n");
       ob->set_attack_everyone(1);
       ob->load_chat(2, ({
                1, "@eye $lname$",
                1, ":seems to be sizing $lcname$ up as an opponent.",
                1, "'Another beer please."
       }));
       ob->load_a_chat(30, ({
                1, "'PUB BRAWL!",
                1, "'Join in the Brawl!!!",
                1, ":smashes a chair over $acname$ head."
       }));
      ob->add_triggered_action("bing", "pub_brawl", HOSPITAL, "pub_brawl");
      ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
      ob->add_property("monster_type", type);
 /*
/ob->add_ac("bing","blunt",({10,5,5}));
      ob->add_ac("bing2", "sharp", ({ 10, 4, 5 }) );
      ob->add_ac("bing2", "pierce", ({ 10, 2, 5 }) );
 */
      ARMORY->request_weapon("bastard_sword",40+random(40))->move(ob);
      ARMORY->request_armour("chainmail",40+random(40))->move(ob);
 /*
      ARMORY->request_armour("gloves",40+random(40))->move(ob);
*/
ob->init_equip();
      return ob;
    case "wulfgar":
      ob = clone_object(MONSTER);
      ob->set_name("wulfgar");
      ob->set_main_plural("barbarians looking like Wulfgar");
      ob->set_race("human");
      ob->set_class("fighter");
      ob->set_level(12);
      ob->set_short("Wulfgar");
      ob->add_triggered_action("bing", "pub_brawl", HOSPITAL, "pub_brawl");
      ob->set_long(
"This is Wulfgar the barbarian. He was once once a hero in the north, but "+
"now he spends most of his time here, drinking and relaxing. He still loves "+
"a good brawl however, so he's sure to join any fights.\n");
      ob->adjust_money(random(100), "copper");
      ob->set_al(-150);
      ob->join_fights("Wulfgar announces loudly: PUB BRAWL!\n");
      ob->set_attack_everyone(1);
      ob->load_chat(3, ({
1, "@burp",
1, "'More scumble please.\n",
1, "@stumble",
      }));
      ob->load_a_chat(30, ({
1, "'PUB BRAWL!\n",
1, "'I love a good Brawl.\n",
1, ":smashes you with a club.\n"
      }));
      ob->add_property("monster_type", type);
      ARMORY->request_weapon("club",40+random(40))->move(ob);
 /*
      ob->add_ac("resist", "blunt", ({ 10, 5, 5 }) );
      ob->add_ac("resist2", "sharp", ({ 10, 4, 5 }) );
      ob->add_ac("resist2", "pierce", ({ 10, 2, 5 }) );
*/
      ARMORY->request_armour("leather",40+random(40))->move(ob);
ob->init_equip();
      return ob;
    default:
      ob = clone_object(MONSTER);
      ob->set_name("failure");
      ob->set_alias("d/fr/hospital#"+type+file_name(previous_object()));
      ob->set_short("failure");
      ob->set_long("Please inform a creator of this object.\n");
      ob->add_property("monster_type", type);
      return ob;
  }
}

void pub_brawl(object ob, mixed where, object me) {
  mixed *arr;
  int i;

  arr = (mixed *)previous_object()->query_current_room()->query_dest_dir();
  if (!arr)
    return ;
  if ((i = member_array(where, arr)) == -1) {
    if (!objectp(where))
      where = find_object(where);
    else
      where = file_name(where);
    if ((i = member_array(where, arr)) == -1)
      return ; /* we cant get there (sniff) */
  }
  previous_object()->init_command(arr[i-1]);
}

void regen_after_death() {
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

void death() {
  call_out("do_pick_up", 0, previous_object());
}

void do_pick_up(object ob) {
  ob->do_command("'Thank you for the nice booty!\n");
  ob->do_command("get all from corpses");
  ob->run_away();
}
