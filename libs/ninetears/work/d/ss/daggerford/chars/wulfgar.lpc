// Wulfgar...

inherit "/obj/monster";

void setup() {    
      set_name("wulfgar");
      set_main_plural("barbarians looking like Wulfgar");
      set_race("human");
	set_random_stats(6, 18);
      set_class("fighter");
      set_level(12);
      set_short("Wulfgar");
      add_triggered_action("bing", "pub_brawl",  this_object(), "pub_brawl");
      set_long(
"This is Wulfgar the barbarian. He was once once a hero in the north, but "+
"now he spends most of his time here, drinking and relaxing. He still loves "+
"a good brawl however, so he's sure to join any fights.\n");
      adjust_money(random(100), "copper");
      set_al(-150);
      set_join_fight_mess("Wulfgar announces loudly: PUB BRAWL!\n");
      set_attack_everyone(1);
      load_chat(10, ({
1, "@burp",
1, "'More scumble please.\n",
1, "@stumble",
      }));
      load_a_chat(30, ({
1, "'PUB BRAWL!\n",
1, "'I love a good Brawl.\n",
1, ":smashes you with a club.\n"
      }));
      new("/baseobs/weapons/club")->move(this_object());
 /*
      add_ac("resist", "blunt", ({ 10, 5, 5 }) );
      add_ac("resist2", "sharp", ({ 10, 4, 5 }) );
      add_ac("resist2", "pierce", ({ 10, 2, 5 }) );
*/
      new("/baseobs/armours/leather")->move(this_object());
      this_object()->init_equip();
} /* setup */
