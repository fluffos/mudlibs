// Metals Vendor

#include <std.h>

inherit VENDOR;



void create() {
   object ob;
   ::create();
   set_name("trader");
   set_short("%^C142%^Oennan Vigilhorn%^C145%^, Master of %^C222%^Metals%^CRST%^");
   set_id(({ "oennan","Oennan","Oennan Vigilhorn","vendor","shopkeep"}));
   set_long("This %^C060%^monstrously%^CRST%^ tall %^C088%^minotaur%^CRST%^ male towers over everyone else in the %^C110%^institute%^CRST%^. He has %^C088%^thick red fur%^CRST%^ and is dressed in a %^C076%^c%^C026%^o%^C076%^lor%^C026%^f%^C076%^ul k%^C026%^i%^C076%^lt%^CRST%^, but little else. His body is humanoid, but bustling with %^C088%^muscles%^CRST%^. His body is criss crossed in %^C197%^old scars%^CRST%^, which look like they were from some %^C242%^barb%^CRST%^ or %^C243%^whip%^CRST%^. His head is that of a %^C124%^bull%^CRST%^, with long wickedly sharp %^C243%^horns%^CRST%^. His eyes though bear none of the %^C124%^savagery%^CRST%^ you might have seen in others of his species, and instead he looks with careful consideration at everything happening in his shop.\n");
   set_race("minotaur");
   set_stats("intelligence",14);
   set_stats("wisdom",18);
   set_stats("strength",20);
   set_stats("charisma",16);
   set_stats("dexterity",12);
   set_stats("constitution",14);
   set_class("fighter");
   set_mlevel("fighter",30);
   set_guild_level("fighter",30);
   set_alignment(4);
   set_gender("male");
   set_size(3);
   set_exp(0);
   set_overall_ac(-10);
   set_hd(35,15);
   set_max_hp(400);
   set_hp(query_max_hp());
   set("aggressive",0);
   set_emotes(2, ({
"%^C111%^Several %^C109%^students%^C111%^ purchase some %^C242%^billets%^C111%^ and rush back to their work%^CRST%^",
"%^C243%^There is a flash of %^C196%^fire %^C243%^and %^C251%^smoke %^C243%^from the forge%^CRST%^",
"%^C059%^The %^C088%^minotaur %^C059%^carefully weighs a %^C226%^billet %^C059%^against the %^C251%^counter weights%^CRST%^",
}), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech speak thick tsvarnen accent");


    ob = new("/d/common/obj/armour/cloak_hooded");
       ob->move(TO);
       ob->set_short("%^C059%^A t%^C063%^a%^C059%^rt%^C063%^a%^C059%^n %^C063%^k%^C059%^i%^C063%^l%^C059%^t%^CRST%^");
       ob->set_property("size",3);
       ob->set_property("enchantment",3);
       ob->se_property("monsterweapon",1);
       command("wear cloak");

   set_storage_room("/d/npc/storage/deku_metal_storage");
}
