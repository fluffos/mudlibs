//undead captain

#include <std.h>
#include "../graez.h"


inherit SHELL;

int i;
object ob,the_monster;

void create(){
   ::create();
   the_monster = this_object();
  

i = random(2);
switch(i)
{
        case 0 :

    set_name("robed deathlock");
    set_short("%^C057%^robed %^C067%^deathlock%^CRST%^");
    set_long("Dressed in a %^C057%^flowing robe%^CRST%^ that seems to move on its own volition, this %^C093%^undead travesty%^CRST%^ is a magic user that has betrayed its oath and has been made into an %^C093%^undead %^CRST%^create of awesome power. Its eyes still %^C162%^glow %^CRST%^with power and it has a hunger for %^C067%^destruction%^CRST%^.");
    set_id(({"captain","undead captain","deathlock","robed deathlock","Robed Deathlock"}));

    set_class("fighter");
    set_guild_level("fighter", 25);
    set_mlevel("fighter",25);
    set_class("cleric");
    set_guild_level("cleric", 25);
    set_mlevel("cleric",25);
    set_alignment(9);
        
    set_monster_feats(({
        "perfect caster",
        "spell focus",
        "spell penetration",
        "greater spell penetration",
        "spell power",
       "blindfight",
           "Shield proficiency",
    }));

    set_spells(({ "mass harm",
                  "harm",
                  "limb attack",
                  "lightning bolt",
                  "umbral strike",
 })); 
       
    set_spell_chance(90);
        
    break;
        case 1 :

    set_name("shambling skeletal infantry");
    set_short("%^C248%^shambling %^C255%^skeletal %^C244%^infantry%^CRST%^");
    set_long("Dressed in %^C064%^disgusting %^CRST%^yet solid %^C242%^heavy armor%^CRST%^, this %^C231%^skeleton %^CRST%^was part of an elite unit torn down and turned into %^C093%^undead %^CRST%^warriors. They have more power than the average %^C231%^skeleton %^CRST%^and seem to work with some intelligence");
    set_id(({"captain","undead captain","skeletal infantry","Skeletal Infantry","infantry","Infantry"}));

    set_attack_bonus(8);
    set_class("fighter");
    set_guild_level("fighter", 25);
    set_mlevel("fighter",25);
    set_class("paladin");
    set_guild_level("paladin", 25);
    set_mlevel("paladin",25);

    set_monster_feats(({
        "weapon focus",
        "expertise",
        "knockdown",
        "powerattack",
        "shatter",
        "sunder",
        "rush",
        "blindfight",
        "improved rush",
                "Shield proficiency",
                "Shield proficiency",
                "shield focus",
                "counter",
                "reflection",
                
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

    set_func_chance(80);

    break;
}

    set_race("undead");
    rank = 3;
    faction = 2;

    set_max_hp(500);
    set_hp(query_max_hp());
    set_overall_ac(-20);


        set_stats("strength", 25);
    set_stats("dexterity",25);
    set_stats("wisdom",20);
    set_stats("constitution",20);
    set_new_exp(25,"normal");
    set_sight_bonus(10);
    set_damage_bonus(8);
    set_property("full attacks",1);
    set_property("no dominate",1);
    set_property("no death",1);
    set_property("full attacks",1);

    ob = new("/d/common/obj/armour/field");
       ob->move(the_monster);
       ob->set_property("enchantment",4);
       ob->set_property("monsterweapon",1);
       command("wear field");

    ob = new("/d/common/obj/armour/shield");
       ob->move(the_monster);
       ob->set_property("enchantment",4);
       ob->set_property("monsterweapon",1);
       command("wear shied");

ob = new(OBJ"mace");
       ob->move(the_monster);
       ob->set_property("enchantment",4);
       ob->set_property("monsterweapon",1);
       command("wield mace");
}


void rushit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(the_monster)) return;
   the_monster->force_me("rush "+targ->query_name());
}


void kdit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(the_monster)) return;
   the_monster->force_me("knockdown "+targ->query_name());
}

void flashit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(the_monster)) return;
   the_monster->force_me("flash "+targ->query_name());
}


void shatit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(the_monster)) return;
   the_monster->force_me("shatter "+targ->query_name());
}

