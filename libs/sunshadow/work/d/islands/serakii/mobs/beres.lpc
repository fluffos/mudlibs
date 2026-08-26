// wood Vendor

#include <std.h>

inherit VENDOR;



void create() {
   object ob;
   ::create();
   set_name("trader");
   set_short("%^C142%^Beres Quijano%^C101%^, the%^CRST%^ %^C028%^Woodsman%^CRST%^");
   set_id(({ "beres","Bares","Bares Quijano","vendor","shopkeep"}));
   set_long("Dressed in %^C094%^heavy leathers%^CRST%^, this "+
   "%^C142%^half-elf's%^CRST%^ features lean more heavily to his "+
   "%^C028%^wood elf%^CRST%^ ancestry. His chin and nose are sharp "+
   "and angular and his %^C208%^coppery%^CRST%^ long hair barely "+
   "hides one %^C221%^long elven ear%^CRST%^. Strangely his other "+
   "%^C221%^ear %^CRST%^is completely gone. Under his %^C094%^leather "+
   "armor%^CRST%^ he is comfortably dressed for "+
   "the %^C028%^wilderness%^CRST%^.\n");
   set_race("half-elf");
   set_stats("intelligence",14);
   set_stats("wisdom",18);
   set_stats("strength",20);
   set_stats("charisma",16);
   set_stats("dexterity",12);
   set_stats("constitution",14);
   set_class("ranger");
   set_mlevel("ranger",30);
   set_guild_level("raner",30);
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
"%^C022%^Beres %^C102%^absently rubs at the side of his head where he is missing an %^C220%^ear%^C102%^.%^CRST%^",
"%^C101%^A %^C037%^student %^C101%^looks over the %^C136%^display cases%^CRST%^",
"%^C142%^The silence and %^C108%^serenity %^C142%^here reminds you of a %^C022%^forest%^CRST%^",
}), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech %^C134%^speak in a %^C175%^soft %^C134%^lilt%^CRST%^");


    ob = new("/d/common/obj/armour/leather");
       ob->move(TO);
       ob->set_short("%^C100%^scarred leather armor%^CRST%^");
	   ob->set_long("%^C100%^scarred leather armor%^CRST%^");
       ob->set_property("size",2);
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wear leather");

   set_storage_room("/d/islands/serakii/storage/serakii_wood_storage");
}

