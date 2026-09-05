//awp.c


#include <ansi.h>
#include <weapon.h>
inherit SWORD;
#include "cs_weapon.h"
void create()
{       
	seteuid(getuid());
	set_name(HIY"狙击步枪"NOR, ({ "awp" }));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set_weight(1);
		set("value", 1);
		set("material", "steel");
		set("unit", "杆");
		set("long", "英国L96A1狙击步枪，是英国精密仪器制造公司为执行狙击任务而研制的步枪\n");
		set("bullets", 10);	
		set("precision", 90);		
		set("continue_shot_miss_interval", 5);		//连续发枪，如果间隔小于此值，命中率减半
		set("busy_time", 6);
		set("damage",70);
		set("random_damage",35);		//附加随机伤害，总damage = query("damage") + random(query("random_damage"));
		set("hs_rate",50);				//爆头率，伤害加倍，如果造成对方死亡则宣布爆头
		set("wield_msg", "$N把肩上的$n里握在手中。\n");
		set("unequip_msg", "$N将手中的$n挂回肩上。\n");
		set("cs/type",CS_MAINGUN);
		set("cs/value",3000);
	}
	init_sword(1);
	setup();
}

