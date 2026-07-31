// ITEM Made by player(渡唐:a1658754_1) /data/item/a/a1658754_1-xuanbing.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar  7 15:19:41 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("玄冰[2;37;0m", ({ "xuanbing" }));
	set_weight(7500);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[37m上古寒铁[2;37;0m炼制而成的一柄剑。
冰寒[2;37;0m
剑柄上刻着一行小字：渡唐(a1658754_1)
");
	set("value", 1500000);
	set("point", 154);
	set("material", "steel");
	set("wield_msg", "散发寒气[2;37;0m\n");
	set("unwield_msg", "随手一挥，便入鞘内[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
