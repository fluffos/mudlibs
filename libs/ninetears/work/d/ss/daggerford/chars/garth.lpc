// Garth the pub brawler...

inherit "/obj/monster";

void setup() {    
      set_name("garth");
      set_race("human");
      set_class("fighter");
      set_level(14);
      set_short("Garth the Pub-Brawler");
	set_random_stats(6, 18);
      set_main_plural("Pub-Brawlers");
      set_long(
"This is Garth the Pub-Brawler, renowned cutthroat and bad guy.  He hangs "+
"around in Lady Luck Tavern, just hoping for a fight. He'll be the first "+
"to join any fight that might start here.\n");
       add_alias("cutthroat");
       add_alias("pub-brawler");
       adjust_money(random(100), "copper");
       set_join_fight_mess("Garth gleefully exclaims: PUB BRAWL!\n");
       set_attack_everyone(1);
       load_chat(2, ({
                1, "@eye $lname$",
                1, ":seems to be sizing $lcname$ up as an opponent.",
                1, "'Another beer please."
       }));
       load_a_chat(30, ({
                1, "'PUB BRAWL!",
                1, "'Join in the Brawl!!!",
                1, ":smashes a chair over $acname$ head."
       }));
      add_triggered_action("bing", "pub_brawl", this_object(),  "pub_brawl");
      add_triggered_action("bing2", "event_death", this_object(), "death");
      new("/baseobs/weapons/bastard_sword")->move(this_object());
      new("/baseobs/armours/chainmail")->move(this_object());
 /*
      ARMORY->request_armour("gloves",40+random(40))->move(ob);
*/
      this_object()->init_equip();
} /* setup */
