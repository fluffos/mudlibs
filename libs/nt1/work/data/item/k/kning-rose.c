// SN:15Y<DLTg87V;2JPN
// ITEM Made by player(唐棠:kning) /data/item/k/kning-rose.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Aug  2 12:08:19 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("蔷薇[2;37;0m", ({ "rose" }));
	set_weight(7500);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[37m上古寒铁[2;37;0m炼制而成的一柄剑。
滴血的蔷薇，随风轻吟[2;37;0m
剑柄上刻着一行小字：唐棠(kning)
");
	set("value", 1500000);
	set("point", 97);
	set("material", "steel");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
