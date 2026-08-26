
//Human Corporal

#include <std.h>
#include "../graez.h"


inherit MONSTER;

int i; 
object ob;

void create(){
   ::create();

    set_name("Graez Deserter");
    set_short("%^C137%^G%^C130%^r%^C137%^a%^C094%^"+
	"e%^C137%^z D%^C094%^e%^C137%^s%^C095%^e%^C137%^r"+
	"t%^C130%^e%^C137%^r%^CRST%^");
    set_long("%^C066%^dressed in %^C094%^ragged "+
	"clothing%^C066%^ covered in %^C202%^filth %^C066%^and "+
	"%^C058%^detritus %^C066%^from the forest. They have "+
	"a %^C062%^half crazed %^C066%^look in their face and twitch "+
	"randomly. He faced the %^C243%^battlefields %^C066%^of "+
	"of %^C249%^Graez %^C066%^and that left him a ruined man. In "+
	"both hands he wields %^C242%^knuckles %^C066%^that seem to "+
	"be from the %^C059%^undead %^C066%^he fought.%^CRST%^");
    set_id(({"deserter","graez deserter","Deserter","Graez Deserter","human","soldier"}));  
 
    set_race("human");
   
    set_max_hp(500);
    set_hp(query_max_hp());
    set_overall_ac(-10);
    set_class("fighter");
    set_guild_level("fighter", 22);
    set_mlevel("fighter",22);
    set_class("monk");
    set_guild_level("monk", 22);
    set_mlevel("ranger",22);
    set_attack_bonus(8);

    set_stats("strength", 20);
    set_stats("dexterity",20);
    set_stats("constitution",20);
    set_new_exp(25,"normal");
    set_sight_bonus(10);
    set_property("full attacks",1);
    set_property("no dominate",1);
    set_alignment(9);
    set_moving(1);
    set_speed(40);
    set("aggressive", 30);

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
	    "spinning kit"
    }));

    set_funcs(({
        "rushit",
        "rushit",
        "spinkick",
        "spinkick",
        "flashit",
        "kdit",
        "shatit"
    }));
    set_property("full attacks",1);
    set_func_chance(80);


    ob = new("/d/common/obj/armour/cloak_hooded");
       ob->move(this_object());
       ob->set_property("monsterweapon",1);
       command("wear cloak");

    ob = new(OBJ"undead_claws");
       ob->move(this_object());
       if(random(4)) ob->set_property("monsterweapon",1);
       command("wield claws");
	   
    ob = new(OBJ"undead_claws");
       ob->move(this_object());
       if(random(4)) ob->set_property("monsterweapon",1);
       command("wield claws");
}


void rushit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(this_object())) return;
   this_object()->force_me("rush "+targ->query_name());
}


void kdit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(this_object())) return;
   this_object()->force_me("knockdown "+targ->query_name());
}

void spinkick(object targ){
   if(!objectp(targ)) return;
   if(!objectp(this_object())) return;
   this_object()->force_me("spinning kick");
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
