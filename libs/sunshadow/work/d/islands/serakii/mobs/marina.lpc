// cloth Vendor

#include <std.h>

inherit VENDOR;



void create() {
   object ob;
   ::create();
   set_name("trader");
   set_short("%^C142%^Marina Alameda%^CRST%^,%^C246%^ Keeper of %^C091%^Cloth%^CRST%^");
   set_id(({ "marina","Marina","Marina Alameda","vendor","shopkeep"}));
   set_long("Standing at just over five feet with a %^C061%^svelte build%^CRST%^, this %^C174%^attayan woman%^CRST%^ is resplendent in a %^C128%^beautiful silk sarong%^CRST%^ tied close over her %^C172%^dark olive skin%^CRST%^. %^C128%^Matching ribbons%^CRST%^ are tied in her %^C094%^hair %^CRST%^and around both her wrists. She moves around her shop with the %^C154%^litheness %^CRST%^of a %^C044%^dancer%^CRST%^.\n");
   set_race("human");
   set_stats("intelligence",14);
   set_stats("wisdom",18);
   set_stats("strength",20);
   set_stats("charisma",16);
   set_stats("dexterity",12);
   set_stats("constitution",14);
   set_class("thief");
   set_mlevel("thief",30);
   set_guild_level("thief",30);
   set_alignment(4);
   set_gender("female");
   set_size(3);
   set_exp(0);
   set_overall_ac(-10);
   set_hd(35,15);
   set_max_hp(400);
   set_hp(query_max_hp());
   set("aggressive",0);
   set_emotes(2, ({
"%^C140%^Marina carefully looks over the %^C061%^bolts %^C140%^of cloth%^CRST%^",
"%^C158%^A %^C248%^porter %^C158%^from the %^C094%^docks %^C158%^delivers several new bolts of %^C138%^cloth%^CRST%^",
"%^C110%^One of the %^C043%^institute instructors%^CRST%^ %^C110%^rushes through,%^CRST%^ %^C158%^students%^C110%^ struggling to keep up!%^CRST%^",
}), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech %^C134%^speak in a %^C175%^soft %^C134%^lilt%^CRST%^");


    ob = new("/d/common/obj/armour/cloak_hooded");
       ob->move(TO);
       ob->set_short("%^C125%^A silk sarong%^CRST%^");
	   ob->set_long("%^C125%^A silk sarong%^CRST%^");
       ob->set_property("size",3);
       ob->set_property("enchantment",3);
          ob->set_property("monsterweapon",1);
       command("wear cloak");

   set_storage_room("/d/islands/serakii/storage/serakii_cloth_storage");
}
