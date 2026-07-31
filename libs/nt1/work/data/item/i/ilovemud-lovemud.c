// SN:A\TP`1gEnRU`iU9U
// ITEM Made by player(爱马德:ilovemud) /data/item/i/ilovemud-lovemud.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Sep 17 09:36:04 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("蛇矛[2;37;0m", ({ "lovemud" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[37m精铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：爱马德(ilovemud)
");
	set("value", 700000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
