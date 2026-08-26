//human captain

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

    set_name("armored human battle priest");
    set_short("%^C243%^armored %^C111%^human %^C038%^battle priest%^CRST%^");
    set_long("This %^C068%^priest%^CRST%^, a veteran of a hundred campaigns is dressed in %^C242%^heavy armor%^CRST%^ adorned with %^C031%^sigils %^CRST%^of his faith. He walks with the assuredness of one that knows their cause is %^C255%^just %^CRST%^and %^C226%^true %^CRST%^and that they are all that stands between the humans of %^C231%^Graez %^CRST%^and the ravaging %^C093%^undead%^CRST%^. In one hand he wears a %^C067%^large shield%^CRST%^ and in the other a %^C250%^glowing mace%^CRST%^.");
    set_id(({"captain","human captain","armored human battle priest","battle priest","priest","armored priest"}));

    set_class("fighter");
    set_guild_level("fighter", 25);
    set_mlevel("fighter",25);
    set_class("cleric");
    set_guild_level("cleric", 25);
    set_mlevel("cleric",25);	
    set_alignment(1);
	
    set_monster_feats(({
        "perfect caster",
        "spell focus",
        "spell penetration",
        "greater spell penetration",
        "spell power",
       "blindfight",
	   "Shield proficiency",
    }));

    set_spells(({ "death is undeath",
                  "limb attack",
                  "cure mass critical wounds",
                  "holy word",
                  "glacier",
 })); 
	
    set_spell_chance(90);
	
    break;
        case 1 :

    set_name("trained human templar");
    set_short("%^C192%^trained %^C066%^human %^C245%^templar%^CRST%^");
    set_long("Dressed in %^C241%^heavy armor%^CRST%^ and hefting their %^C066%^weapon %^CRST%^like a %^C226%^sacred relic%^CRST%^, this %^C067%^templar%^CRST%^ has been dispatched by their church to fight alongside the defenders of %^C231%^Graez %^CRST%^against the %^C093%^undead%^CRST%^. They wear a %^C246%^shield %^CRST%^adorned with %^C248%^scripts %^CRST%^and %^C111%^runes %^CRST%^from their temple and work with professional efficiency in dispatching %^C093%^undead%^CRST%^.");
    set_id(({"captain","human captain","human templar",
	"templar","Templar","trained templar"}));

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

    set_race("human");
    rank = 3;
    faction = 1;

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
       ob->move(TO);
       ob->set_property("enchantment",4);
       ob->set_property("monsterweapon",1);
       command("wear field");

    ob = new("/d/common/obj/armour/shield");
       ob->move(TO);
       ob->set_property("enchantment",4);
       ob->set_property("monsterweapon",1);
       command("wear shield");

    ob = new("/d/antioch/ruins/obj/heavens_mace");
       ob->move(TO);
       ob->set_property("enchantment",4);
       ob->set_property("monsterweapon",1);
       command("wield mace");
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

