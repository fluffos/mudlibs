// SN:eh^`O1SfYa2@cQbl
// ITEM Made by player(天蛆:ququ) /data/item/q/ququ-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jul 16 11:16:47 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m泰坦之剑[2;37;0m", ({ "sword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;32m传说中泰坦巨人遗落在世间的神器。[2;37;0m
剑柄上刻着一行小字：天蛆(ququ)
");
	set("value", 2100000);
	set("point", 182);
	set("material", "magic stone");
	set("wield_msg", "[1;32m突然一道闪电劈开混沌的暗黑世界[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
