// SN:W8Uh94mma34AJi^N
// ITEM Made by player(骑士:qishi) /data/item/q/qishi-ccc.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Nov  9 13:47:04 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("剑甲[2;37;0m", ({ "ccc" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：骑士(qishi)
");
	set("value", 2100000);
	set("point", 822);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
