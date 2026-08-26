// provost

#include <std.h>

inherit VENDOR;



void create() {
   object ob;
   ::create();
   set_name("trader");
   set_short("%^C143%^Rasdal Hastings%^CRST%^, %^C059%^Provost of the%^CRST%^ %^C045%^Institute%^CRST%^");
   set_id(({ "rasdal","rasdal hastings","Rasdal Hastings","provost","clerk"}));
   set_long("This %^C143%^elderly%^CRST%^ human man's "+
      "frame is bent from %^C060%^age%^CRST%^, but "+
      "from the %^C161%^calluses%^CRST%^ on his "+
      "hands and the %^C088%^sinewy muscles%^CRST%^ he "+
      "still has, you can tell this man has never slowed. "+
      "%^C255%^Whispy white hair%^CRST%^ escapes from under a "+
      "%^C094%^leather cap%^CRST%^ and he wears a %^C094%^heavy "+
      "apron%^CRST%^ stained with decades of work. He looks over "+
      "the %^C044%^institute%^CRST%^ with %^C046%^keen green%^CRST%^ "+
      "%^C046%^eyes%^CRST%^ and a soft quiet authority. Under "+
      "his %^C094%^apron%^CRST%^ he wears simple homespun clothes. "+
      "When not handing out %^C247%^tools%^CRST%^ he speaks "+
      "quietly with students and teachers alike from all "+
      "the disciplines, offering guidance and congradulations.\n");
   set_race("human");
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
"%^C189%^A group of %^C060%^students%^C189%^ rush past, you hear a %^C246%^teacher%^C189%^ scold them.%^CRST%^\n",
"%^C106%^Rasdal hands over a %^C248%^tool kit%^C106%^ to a villager.%^CRST%^\n",
"%^C113%^Rasdal %^C034%^smiles%^C113%^ as he looks out on the %^C045%^institute%^C113%^. %^CRST%^\n",
}), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech %^C060%^speak in a calm %^C066%^reassuring%^C060%^ voice%^CRST%^");


    ob = new("/d/common/obj/armour/cloak_hooded");
       ob->move(TO);
       ob->set_short("%^C142%^o%^C059%^l%^C142%^d apr%^C058%^o%^C142%^n%^CRST%^");
       ob->set_long("%^C142%^o%^C059%^l%^C142%^d apr%^C058%^o%^C142%^n%^CRST%^");
       ob->set_property("size",3);
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wear cloak");

   set_storage_room("/d/islands/serakii/storage/serakii_tool_storage");
}
