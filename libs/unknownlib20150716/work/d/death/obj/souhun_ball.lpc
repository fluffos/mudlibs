#include <ansi.h>
inherit FABAO;

void create()
{
	set_name("搜魂球",({"souhun qiu","ball","qiu",}));
   	set_weight(1000);
   	set("long", "阎罗地府的法宝，具有收取(shouhun)残魂的效果。\n");
	if( clonep() )
        	set_default_object(__FILE__);
	else 
	{
        	set("unit", "个");
                set("material", "fabao");
                set("value", 0);
                set("no_get", 1);
		set("no_give", 1);
                set("max_num",9);
                set("num",0);
		set("armor_prop",([
			"max_kee" : 50,
			"max_sen" : 50,
			"max_force" : 20,
			"max_mana"  : 20,
		]));
		set("fabao",([
			"max_attack_qi" : 5,
			"max_attack_shen" : 5,
			"max_defense_qi" : 5,
			"max_defense_shen" : 5,
			"combat_damage" : 10,
			"combat_def"	: 10,
			"spells_damage" : 10,
			"spells_def"	: 10,
		]));	
		set("ji_time",6);
		set("fabao_type",({"attack"})); 
        }
 	setup();
}