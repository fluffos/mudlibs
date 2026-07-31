// SN::Dji:[EM^QDL>l:5
// ITEM Made by player(风月儿:flycool) /data/item/f/flycool-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Oct 11 11:53:00 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m黄金手剑[2;37;0m", ({ "jian" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;31m这是黄金十二宫中山羊星座锋利无比的神之剑。[2;37;0m
剑柄上刻着一行小字：风月儿(flycool)
");
	set("value", 2100000);
	set("point", 140);
	set("material", "magic stone");
	set("wield_msg", "[37m一鼓无形的剑气从四面八方涌来，手剑不知什么时候已经落入手中。[2;37;0m\n");
	set("unwield_msg", "[1;33m杀气冲天而去，手剑化做无数繁星，消失在天宇之间。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
