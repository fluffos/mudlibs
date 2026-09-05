//m4a1.c


#include <ansi.h>
#include <weapon.h>
inherit SWORD;
#include "cs_weapon.h"
void create()
{       
	seteuid(getuid());
	set_name(HIY"M4A1卡宾枪"NOR, ({ "m4a1", "m4" }));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set_weight(1);
		set("value", 1);
		set("material", "steel");
		set("unit", "杆");
		set("long", "美国5.56mm北大西洋公约组织口径M4A1卡宾枪。\n");
		set("bullets", 30);	
		set("precision", 80);		
		set("continue_shot_miss_interval", -5);		//连续发枪，如果间隔小于此值，命中率减半
		set("damage",15);
		set("random_damage",10);		//附加随机伤害，总damage = query("damage") + random(query("random_damage"));
		set("hs_rate",40);				//爆头率，伤害加倍，如果造成对方死亡则宣布爆头
		set("wield_msg", "$N把肩上的$n里握在手中。\n");
		set("unequip_msg", "$N将手中的$n挂回肩上。\n");
		set("busy_time", -5);
		set("cs/type",CS_MAINGUN);
		set("cs/value",2000);
	}
	init_sword(1);
	setup();
}

