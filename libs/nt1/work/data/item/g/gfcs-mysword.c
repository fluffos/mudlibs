// SN:Y<fBMminWlQ]I^ad
// ITEM Made by player(段玉兰:gfcs) /data/item/g/gfcs-mysword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Oct 29 22:25:06 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m赤焰[2;37;0m", ({ "mysword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：段玉兰(gfcs)
");
	set("value", 2100000);
	set("point", 703);
	set("material", "magic stone");
	set("wield_msg", "[1;31m$N右手往外一推，一道炽热的烈焰猛地自手中碰了出来。[2;37;0m\n");
	set("unwield_msg", "[1;32m$N双手一圈，烈焰顿消。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
