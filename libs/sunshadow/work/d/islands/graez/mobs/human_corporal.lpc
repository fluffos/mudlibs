
//Human Corporal

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

    set_name("human infantry");
    set_short("%^C245%^human %^C059%^in%^C061%^f%^C059%^ant%^C061%^r%^C059%^y%^CRST%^");
    set_long("dressed in %^C244%^reinforced field plate%^CRST%^, this soldier is a veteran of the conflict on %^C255%^Graez %^CRST%^and has returned enough times from the %^C058%^field %^CRST%^to learn from the fight. He wields a %^C246%^morning star%^CRST%^ more suitable than a %^C245%^sword %^CRST%^for bashing in the %^C092%^undead%^CRST%^.");
    set_id(({"corporal","human corporal","human infantry","Human Infantry","Infantry","infantry"}));  
    break;
        case 1 :

    set_name("human sellsword");
    set_short("%^C142%^human %^C220%^sellsword%^CRST%^");
    set_long("This human is a %^C059%^sell sword%^CRST%^, a common brigand who earns %^C220%^gold %^CRST%^for every day they fight on %^C255%^Graez%^CRST%^. Their commitment to %^C220%^gold %^CRST%^being higher than duty not withstanding, they fight with %^C088%^ferocity %^CRST%^and skill against the %^C092%^undead %^CRST%^that face them.");
    set_id(({"corporal","human corporal","sellsword","human sellsword","Human Sellsword","Sellsword"}));  
    break;
}
 
    set_race("human");
    rank = 2;
    faction = 1;
   
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
    set_alignment(1);

    set_stats("strength", 20);
    set_stats("dexterity",20);
    set_stats("constitution",20);
    set_new_exp(25,"normal");
    set_sight_bonus(10);
    set_property("full attacks",1);
    set_property("no dominate",1);
    set_property("no death",1);

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


    ob = new("/d/common/obj/armour/field");
       ob->move(TO);
       ob->set_property("enchantment",4);
       ob->set_property("monsterweapon",1);
       command("wear field");

    ob = new("/d/common/obj/weapon/morningstar");
       ob->move(TO);
       ob->set_property("enchantment",4);
       ob->set_property("monsterweapon",1);
       command("wield morningstar");
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
