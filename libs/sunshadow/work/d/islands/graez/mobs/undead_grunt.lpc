//Undead Grunt

#include <std.h>
#include "../graez.h"


inherit SHELL;

int i; 
object ob;

void create(){
   ::create();
   
i = random(2);
switch(i)
{
	case 0 : 

   set_name("ragged skeleton");
   set_short("%^C060%^r%^C243%^a%^C060%^g%^C095%^g%^C060%^ed s%^C242%^k%^C060%^elet%^C095%^o%^C060%^n%^CRST%^");
   set_long("This %^C245%^skeleton %^CRST%^is barely "+
   "out of the ground, with bits of %^C094%^soil "+
   "%^CRST%^and torn strips of %^C060%^clothing%^CRST%^ "+
   "hanging off of it. It moves with %^C055%^undead "+
   "energy%^CRST%^ towards anything living. It wields "+
   "a %^C251%^sword %^CRST%^in one hand and "+
   "wears %^C244%^armor%^CRST%^.");
   set_id(({"grunt","undead grunt","skeleton","ragged skeleton"}));  
    break;
	case 1 :

   set_name("shambling zombie");	
   set_short("%^C028%^sh%^C059%^a%^C028%^mb%^C060%^l%^C028%^ing z%^C060%^o%^C028%^mb%^C059%^i%^C028%^e%^CRST%^");
   set_long("This %^C029%^zombie %^CRST%^is slow, aggressive, and reeks of the %^C055%^undeath%^CRST%^ that has brought it back to movement. Its movements are slow but with intent, and its form is slack but seems to hide considerable %^C088%^strength%^CRST%^. It wields a %^C242%^sword %^CRST%^in one hand and wears %^C059%^tattered armor%^CRST%^.");
   set_id(({"grunt","undead grunt","zombie","shambling zombie"}));

    break;
}
   
   set_race("undead");
   rank = 1;
   faction = 2;
   
   set_max_hp(200);
   set_hp(query_max_hp());
   set_overall_ac(6);
   set_class("fighter");
   set_guild_level("fighter", 18);
   set_stats("strength", 16);
   set_stats("dexterity",16);
   set_stats("constitution",19);
   set_new_exp(25,"normal");
   set_alignment(9);


    ob = new("/d/common/obj/armour/chain");
       ob->move(TO);
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wear chain");

    ob = new("/d/common/obj/weapon/longsword");
       ob->move(TO);
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wield sword");
}


  
   

