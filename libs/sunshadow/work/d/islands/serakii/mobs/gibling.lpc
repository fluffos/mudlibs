
// Chittering Gibling - 2022

#include <std.h>
#include "../serakii.h"

inherit MONSTER;
int lev;

void charge();

void create() 
{
    string me;
    object ob;
    ::create();
    set_name("chittering gibling");
    set_id(({"gibling", "chittering gibling", "Gibling"}));
    
    set_short("%^C143%^ch%^C073%^i%^C143%^tter%^C073%^i%^C143%^ng gi%^C074%^b%^C143%^li%^C074%^n%^C143%^g%^CRST%^");
    set_long("This small %^C055%^demon %^CRST%^is a "+
	"strange thing. While %^C060%^vaguely humanoid%^CRST%^, "+
	"this %^C055%^demon %^CRST%^has been %^C057%^warped%^CRST%^ "+
	"in strange ways. Eyes cover all part of it, with %^C214%^"+
	"eyes %^CRST%^on every spare square inch of skin. The "+
	"eyes themselves are from a hundred different creatures. "+
	"The %^C055%^creature %^CRST%^moves with speed and %^C240%^deadly "+
	"precision%^CRST%^ and %^C060%^chitters %^CRST%^to itself as it does\n");
        
    set_race("demon");
    set_body_type("human");
    set_gender("male");
    set_size(1);
    set_overall_ac(-40);
    set_class("thief");
    
    lev = 50 + random(9);
    set_guild_level("thief",lev);
    set_mlevel("thief", lev);
	
	set_class("assassin");
    set_mlevel("assassin",10);
    set_guild_level("assassin",10);
    
    set_max_hp(lev*40 + random(1000));
    set_hp(query_max_hp());
    set_speed(30);
    	
    //set_nogo(({ }));
    
    set_property("full attacks",1);
	set_property("cast and attack",1);
    set_property("no dominate",1);
    set_property("no tripped", 1);
    set_property("no paralyze",1);
    set_property("no death",1);
    
    set_stats("strength",19);
    set_stats("dexterity",22);
    set_stats("constitution",15);
    set_stats("intelligence", 10);
    set_stats("wisdom", 20);
    set_stats("charisma", 12);
    
    set("aggressive",55);
    me = TO->query_short();
    
        
    set_new_exp(lev, "high");
    
    set_alignment(9);
    set_attack_bonus(10);
    
    set_spells(({"fog cloud","powerword blind","powerword stune"}));
 
    set_spell_chance(60);
    
    set_funcs(({"crit"}));
    
    set_func_chance(90);
	
    set_skill("athletics", 40);

	set_monster_feats(({
	    "combat reflexes",
		"danger sense",
		"perfect caster",
		"mobility",
		"evasion",
		"blade block",
		"impale",
		"light weapon",
		"strength of arm",
		"sweepingblow"
    }));
    add_money("gold",random(5000));
    ob = new(OBJ"bloodwood_axe");
    if(random(6)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield axe");
    ob = new(OBJ"bloodwood_axe");
    if(random(6)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield axe");

    
}



void crit(object targ) 
{
  command("crit "+targ->query_name()+"");
  return;
}


