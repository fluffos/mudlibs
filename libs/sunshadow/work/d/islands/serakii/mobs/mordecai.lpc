// Mordecai - LoKi - 2021


#include <std.h>
#include <daemons.h>
inherit NPC;

void create(){
   object ob;
   ::create();
   set_name("Mordecai Lamoch");
   set_short("%^C171%^Mordecai Lamoch%^C212%^, of the %^C198%^Voice%^CRST%^");
   set_id(({ "mordecai","Mordecai","mordecai lamoch","lamoch","voice","Mordecai Lamoch, of the Voice"}));
   set_long("Dressed in a pure %^C255%^white "+
   "satin robe%^CRST%^, and wearing a %^C255%^satin cap%^CRST%^ "+
   "on his head, this man looks back at you with ill hidden %^C055%^distain%^CRST%^. "+
   "His clothing is the richest fabric, the best cut, and immaculately "+
   "clean. He is likewise %^C222%^clean shaven%^CRST%^ this morning, "+
   "with his %^C241%^black hair%^CRST%^ oiled and slicked back. "+
   "%^C051%^Cyan eyes%^CRST%^ look back from his perfectly symmetrical face.\n");
   set_race("human");
   set_stats("intelligence",20);
   set_stats("wisdom",18);
   set_stats("strength",16);
   set_stats("charisma",16);
   set_stats("dexterity",12);
   set_stats("constitution",14);
   set_class("fighter");
   set_mlevel("fighter",30);
   set_guild_level("fighter",30);
   set_alignment(5);
   set_gender("female");
   set_size(2);
   set_exp(0);
   set_overall_ac(-10);
   set_hd(35,15);
   set_max_hp(400);
   set_hp(query_max_hp());
   set("aggressive",0);

   set_property("no bows",1);
   set_spoken("wizish");
   command("speech %^C242%^speak in an %^C160%^arrogant %^C242%^voice%^CRST%^");

    ob = new("/d/common/obj/armour/robe");
       ob->set_short("%^C255%^A white satin robe%^CRST%^");
       ob->move(TO);
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wear robe");

}
