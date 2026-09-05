//m4a1.c


#include <ansi.h>
#include <weapon.h>
inherit SWORD;
#include "cs_weapon.h"
void create()
{       
	seteuid(getuid());
	set_name(HIY"沙漠之鹰"NOR, ({ "de" }));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set_weight(1);
		set("value", 1);
		set("material", "steel");
		set("unit", "杆");
		set("long", ".357马格南口径的半自动手枪。\n");
		set("bullets", 7);	
		set("precision", 40);		
		set("continue_shot_miss_interval", 0);		//连续发枪，如果间隔小于此值，命中率减半
		set("damage",15);
		set("random_damage",10);		//附加随机伤害，总damage = query("damage") + random(query("random_damage"));
		set("hs_rate",50);				//爆头率，伤害加倍，如果造成对方死亡则宣布爆头
		set("wield_msg", "$N从腰间拿出$n，握在手中。\n");
		set("unequip_msg", "$N将手中的$n插回腰间。\n");
		set("busy_time", -5);
		set("cs/type",CS_PISTOL);
		set("cs/value",300);
	}
	init_sword(1);
	setup();
}

