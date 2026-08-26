
//Human Grunt

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

   set_name("human militia soldier");
   set_short("%^C142%^hu%^C144%^m%^C142%^an %^C246%^milit%^C250%^i%^C246%^a%^C142%^ soldi%^C060%^e%^C142%^r%^CRST%^");
   set_long("Dressed in %^C095%^simple armor%^CRST%^ and wielding a %^C245%^common longsword%^CRST%^, this soldier forms the bulk of the %^C255%^Graez%^CRST%^ militia. He is adequately trained to not fall on the %^C255%^sharp end%^CRST%^ of his weapon but not much more than that. He will however defend the city until his last breath against the %^C061%^undead%^CRST%^.");
   set_id(({"grunt","human grunt","militia militia soldier","human militia","militia","soldier"}));  
    break;
        case 1 :

   set_name("volunteer human %^C142%^villager%^CRST%^");
   set_short("%^C143%^vo%^C106%^l%^C143%^unteer%^C102%^ human %^C143%^vi%^C108%^l%^C143%^lager%^CRST%^");
   set_long("This %^C108%^villager%^CRST%^ comes from somewhere on the mainland and has taken his family's ancestral %^C124%^rusty sword%^CRST%^ and %^C246%^armor%^CRST%^ from a war decades past and has journeyed to %^C255%^Graez%^CRST%^ to fight for humanity. He is completely untrained though will fight any %^C062%^undead%^CRST%^ till his death.");
   set_id(({"grunt","human grunt","volunteer human villager","human volunteer","volunteer","villager"}));  
    break;

}
   
   set_race("human");
   rank = 1;
   faction = 1;
   
   set_max_hp(200);
   set_hp(query_max_hp());
   set_overall_ac(1);
   set_class("fighter");
   set_guild_level("fighter", 18);
   set_stats("strength", 16);
   set_stats("dexterity",16);
   set_stats("constitution",19);
   set_new_exp(25,"normal");
   set_alignment(1);


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
