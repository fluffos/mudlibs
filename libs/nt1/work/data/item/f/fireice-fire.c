// SN:@XI6b6=2WT]`MW7Y
// ITEM Made by player(水灵:fireice) /data/item/f/fireice-fire.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Nov 24 09:47:46 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m火神[2;37;0m", ({ "fire" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;31m它是传说中火神的化身[2;37;0m
剑柄上刻着一行小字：水灵(fireice)
");
	set("value", 2100000);
	set("point", 217);
	set("material", "magic stone");
	set("wield_msg", "[1;31m一阵火光闪过，火神出鞘了[2;37;0m\n");
	set("unwield_msg", "[1;31m一阵火光闪过，火神回鞘了[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
