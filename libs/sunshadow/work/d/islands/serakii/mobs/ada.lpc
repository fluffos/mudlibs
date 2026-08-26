// Librarian - LoKi - 2021


#include <std.h>
#include <daemons.h>
inherit NPC;

void create(){
   object ob;
   ::create();
   set_name("Ada Yates");
   set_short("%^C063%^Ada Yates, %^C059%^Archivist %^C063%^of the %^C035%^Library of Kismet%^CRST%^");
   set_id(({ "ada","Ada","ada yates","archivist","Ada Yates","Ada Yates, Archivist of the Library of Kismet"}));
   set_long("Dressed in a %^C022%^simple peridot robe%^CRST%^, "+
   "this woman in her %^C178%^early fifties%^CRST%^ has all the "+
   "bearing of a %^C054%^queen %^CRST%^in her throne room. She "+
   "eyes the %^C059%^books%^CRST%^, %^C094%^shelves %^CRST%^and "+
   "%^C214%^birds %^CRST%^with authority and each and every "+
   "person here listens when she speaks. She is the head "+
   "archivist of the %^C022%^library %^CRST%^and stands near "+
   "the %^C242%^fountain %^CRST%^like a conductor. Her "+
   "%^C088%^long red hair%^CRST%^ falls in curls over her "+
   "shoulders and %^C028%^deep green eyes%^CRST%^ shine "+
   "with %^C228%^light%^CRST%^. \n");
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
   set_emotes(1, ({
"An %^C124%^extra large %^C009%^robin %^CRST%^swoops down and drops a %^C102%^book%^CRST%^ on a %^C094%^table %^CRST%^for a %^C059%^researcher%^CRST%^, then takes wing again!",
"%^C035%^Ada %^CRST%^directs a flock of %^C100%^starlings %^CRST%^over to a %^C102%^section%^CRST%^ needing cleaning",
"The %^C063%^water %^CRST%^from the %^C242%^fountain %^C116%^bubbles%^CRST%^",
"A pair of %^C255%^Lysarian %^C060%^researchers %^CRST%^walk by, arguing over a %^C100%^text%^CRST%^",
}), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech %^C100%^speak in a %^C064%^deep %^C100%^rich voice%^CRST%^");

    ob = new("/d/common/obj/armour/robe");
       ob->set_short("A peridot robe");
       ob->move(TO);
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wear robe");

}
