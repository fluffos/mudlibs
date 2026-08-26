//Undead Corporal

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

        set_name("dust formed revenant");
        set_short("%^C142%^du%^C060%^s%^C142%^t form%^C061%^e%^C142%^d re%^C060%^v%^C142%^ena%^C059%^n%^C142%^t%^CRST%^");
        set_long("Formed almost entirely of %^C220%^sand%^CRST%^ and %^C060%^dust%^CRST%^, this %^C093%^undead%^CRST%^ creature howls in %^C124%^anger%^CRST%^ at any %^C255%^living%^CRST%^ thing near it. It resembles a %^C245%^soldier%^CRST%^, a human who died on these %^C028%^fields%^CRST%^, but with %^C059%^gray dead skin%^CRST%^. It wields the %^C243%^weapons%^CRST%^ it did in %^C255%^life%^CRST%^, seeking not only to inflict as much pain as possible.");
        set_id(({"corporal","undead corporal","revenant","dust filled revenant","Revenant"}));  
    break;
        
    case 1 :

        set_name("wretched ghoul");
        set_short("%^C109%^wr%^C107%^e%^C109%^tched gho%^C106%^u%^C109%^l%^CRST%^");
        set_long("This thing, at one point was a human, though after some gruesome death it has returned as something %^C106%^monsterous%^CRST%^. Its skin is %^C109%^decrepid%^CRST%^ and falling off of %^C059%^splindly limbs%^CRST%^ though there is an %^C062%^unnatural%^CRST%^ strength in its movements and it leaps forward towards anything %^C255%^alive%^CRST%^ to bring its weapon down on it. It still wears the %^C095%^clothes%^CRST%^ that it did while it was alive, including the %^C248%^armor%^CRST%^ it wore.");
        set_id(({"corporal","undead corporal","ghoul","Ghoul","wretched"}));  
    break;
}
 
    set_race("undead");
    rank = 2;
    faction = 2;
   
    set_max_hp(500);
    set_hp(query_max_hp());
    set_overall_ac(-10);
    set_class("fighter");
    set_guild_level("fighter", 22);
    set_mlevel("fighter",22);
    set_class("ranger");
    set_guild_level("ranger", 22);
    set_mlevel("ranger",22);
    set_attack_bonus(8);

    set_stats("strength", 20);
    set_stats("dexterity",20);
    set_stats("constitution",20);
    set_new_exp(25,"normal");
    set_sight_bonus(10);
    set_property("full attacks",1);
    set_property("no dominate",1);
    set_property("no death",1);
    set_alignment(9);

    set_monster_feats(({
        "weapon focus",
        "expertise",
        "knockdown",
        "powerattack",
        "shatter",
        "sunder",
       "rush",
       "blindfight",
       "improved rush"
    }));

    set_funcs(({
        "rushit",
        "rushit",
        "rushit",
        "rushit",
        "flashit",
        "kdit",
        "shatit"
    }));
    set_property("full attacks",1);
    set_func_chance(80);


    ob = new("/d/common/obj/armour/bronze");
       ob->move(TO);
       ob->set_property("enchantment",4);
       ob->set_property("monsterweapon",1);
       command("wear bronze");

    ob = new("/d/common/obj/weapon/fauchard");
       ob->move(TO);
       ob->set_property("enchantment",4);
       ob->set_property("monsterweapon",1);
       command("wield fauchard");
}


void rushit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("rush "+targ->query_name());
}


void kdit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("knockdown "+targ->query_name());
}

void flashit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("flash "+targ->query_name());
}


void shatit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("shatter "+targ->query_name());
}

