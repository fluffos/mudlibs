// SN:M@F5?IQ<JG29Hdi@
// ITEM Made by player(小草:grass) /data/item/g/grass-blue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Mar 19 00:25:39 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m深蓝判决[2;37;0m", ({ "blue" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：小草(grass)
");
	set("value", 2100000);
	set("point", 566);
	set("material", "magic stone");
	set("wield_msg", "[1;34m比大海更深沉的忧伤☆[1;36m比天空更青蓝的悠远★[30m自九幽地渊之底复现☆[1;31m我以自身鲜血为誓★[1;32m传承彼幽暗之力☆[1;35m赐予所能触及的一切★[1;33m——[1;37m彼之判决[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
