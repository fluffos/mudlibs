// SN:>j6]_R^_0YQgM3]m
// ITEM Made by player(慕容新月:xinyue) /data/item/x/xinyue-lanhua.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Mar 24 09:45:34 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m兰花[1;35m靴[2;37;0m", ({ "lanhua" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
[1;35m一双碧绿可爱的靴子，靴子的面上绣着一朵小小的[1;32m兰花[1;35m。[2;37;0m
靴子缘上刻着一行小字：慕容新月(xinyue)
");
	set("value", 2100000);
	set("point", 119);
	set("material", "silk");
	set("wear_msg", "[1;35m$N羞红了双颊，飞快的穿上一双[1;32m兰花[1;35m靴，穿好之后，脸上的娇羞亦未平复。[2;37;0m\n");
	set("remove_msg", "[1;35m$N躲在一旁，偷偷地把脚下的[1;32m靴子[1;35m脱下。\n在这惊鸿一瞥之下，你看到了一双白生生的[1;37m玉足[1;35m，心下不由得一荡。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/dodge", apply_armor() / 10 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
