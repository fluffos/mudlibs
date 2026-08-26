#include <std.h>
#include <daemons.h>
inherit MONSTER;

create() {
    	::create();
   	set_name("rat");
   	set_id( ({ "rat" }) );
   	set_short("A big rat");
   	set_level(1);
   	set_long("A big rat.\n");
    	set_gender(random(2)?"male":"female");
   	set_race("rat");
   	set_body_type("quadruped");
   	set_alignment(2);
   	set("aggressive",20);
   	set_size(1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",3);
   	set_stats("charisma",3);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
   	set_max_mp(0);
   	set_hd(1,6);
   	set_max_hp((random(20) + 10));
   	set_hp(query_max_hp());
   	set_max_level(5);
   	add_money("copper",random(2));
   	set_exp(250);
}

// Taming DCs: Low - 10, Mid - 25, High - 40, Epic - 55
// Types of DCs: "survival" for wild creatures (snakes, rats, stags, spiders, etc...)
//               "spellcraft" for magical creatures (elementals, sprites, will o wisp, etc...)
//               "dungeoneering" for constructs (clockwork creatures, golems, etc...)
int is_tamable(){ return 1; }
int query_tame_DC(){ return 10; }
string query_DC_type(){ return "survival"; }

