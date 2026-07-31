// SN:7f9bY04BTVhD?Poj
// ITEM Made by player(张飞:ilifemud) /data/item/i/ilifemud-qingfeng.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Sep 24 07:14:17 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m青[1;32m锋[1;37m剑[2;37;0m", ({ "qingfeng" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：张飞(ilifemud)
");
	set("value", 2100000);
	set("point", 200);
	set("material", "magic stone");
	set("wield_msg", "$N一声轻啸，突然乌云密布，天际间划出一道[1;37m闪电，\n[2;37;0m一把[1;36m青锋剑[2;37;0m到了$N手中。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
