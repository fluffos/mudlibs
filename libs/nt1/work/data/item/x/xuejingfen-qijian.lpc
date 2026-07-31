// SN:7bEe>=2I5`5]?^GI
// ITEM Made by player(静静:xuejingfen) /data/item/x/xuejingfen-qijian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 24 16:48:12 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31m天羽[1;33m奇[1;32m剑[2;37;0m", ({ "qijian" }));
	set_weight(7500);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[37m上古寒铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：静静(xuejingfen)
");
	set("value", 1500000);
	set("point", 102);
	set("material", "steel");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
