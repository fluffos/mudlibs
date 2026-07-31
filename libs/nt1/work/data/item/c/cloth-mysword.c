// SN:No[I]h_N5OPkgDi0
// ITEM Made by player(布衣:cloth) /data/item/c/cloth-mysword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Oct 30 14:25:04 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m上帝之剑[2;37;0m", ({ "mysword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;33m上帝杀流氓的神剑[2;37;0m
剑柄上刻着一行小字：布衣(cloth)
");
	set("value", 2100000);
	set("point", 208);
	set("material", "magic stone");
	set("wield_msg", "[1;33m上帝要开杀戒了[2;37;0m\n");
	set("unwield_msg", "[1;33m上帝要开溜了[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
