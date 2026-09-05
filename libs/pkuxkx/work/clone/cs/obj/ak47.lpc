//ak47.c


#include <ansi.h>
#include <weapon.h>
inherit SWORD;
#include "cs_weapon.h"
void create()
{       
	seteuid(getuid());
	set_name(HIY"AK47"NOR, ({ "ak47", "ak" }));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set_weight(1);
		set("value", 1);
		set("material", "steel");
		set("unit", "杆");
		set("long", "这是恐怖分子必备武器，价格便宜量又足，大家都爱用它。\n");
		set("bullets", 30);	
		set("precision", 80);		
		set("continue_shot_miss_interval", 1);		//连续发枪，如果间隔小于此值，命中率减半
		set("damage",20);
		set("random_damage",30);		//附加随机伤害，总damage = query("damage") + random(query("random_damage"));
		set("hs_rate",30);				//爆头率，伤害加倍，如果造成对方死亡则宣布爆头
		set("wield_msg", "$N把肩上的$n里握在手中。\n");
		set("unequip_msg", "$N将手中的$n挂回肩上。\n");
		set("busy_time", -3);
		set("cs/type",CS_MAINGUN);
		set("cs/value",1700);
	}
	init_sword(1);
	setup();
}

