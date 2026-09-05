//knife.c


#include <ansi.h>
#include <weapon.h>
inherit SWORD;
#include "cs_weapon.h"
void create()
{       
	seteuid(getuid());
	set_name(HIY"匕首"NOR, ({ "knife" }));
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set_weight(1);
		set("value", 1);
		set("material", "steel");
		set("unit", "把");
		set("long", "这是防身必备武器。\n");
		set("bullets", 3000000);	//匕首，理论上没有子弹，所以设置一个比较大的数
		set("precision", 30);		
		set("continue_shot_miss_interval", 0);		//连续发枪，如果间隔小于此值，命中率减半
		set("damage",10);
		set("random_damage",10);		//附加随机伤害，总damage = query("damage") + random(query("random_damage"));
		set("hs_rate",30);				//爆头率，伤害加倍，如果造成对方死亡则宣布爆头
		set("wield_msg", "$N从小腿上抽出一把$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插回小腿上。\n");
		set("cs/type",CS_KNIFE);
		set("cs/value",100);
		set("busy_time", -3);
		set("msg_hs", HIC "$N拿出" + query("name")+CYN"，对准$n的头部狠狠地一刀扎下去。结果$n的头部被扎出一个大口子，$n眼看就不行了。\n" NOR);
		set("msg_normal",HIC "$N拿出" + query("name")+CYN"，对准$n狠狠地一刀扎下去。只见$n身上被扎出一个大口子，$n眼看就不行了。\n" NOR);
		set("msg_half",HIC "$N拿出" + query("name")+CYN"，对着$n随意挥了一刀。\n" NOR);
		set("msg_missed",HIC "$N拿出" + query("name")+CYN"，对着$n随意挥了一刀。结果被$n轻松躲开了！\n" NOR);
		
	}
	init_sword(1);
	setup();
}

