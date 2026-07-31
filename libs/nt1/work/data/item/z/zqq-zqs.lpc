// SN:ejW[:@lI2;o\lF3f
// ITEM Made by player(朱七七:zqq) /data/item/z/zqq-zqs.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 23 21:03:20 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("伤心小剑[2;37;0m", ({ "zqs" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
朱七七[2;37;0m
剑柄上刻着一行小字：朱七七(zqq)
");
	set("value", 2100000);
	set("point", 192);
	set("material", "magic stone");
	set("wield_msg", "伤心愈绝之剑[2;37;0m\n");
	set("unwield_msg", "只是未到伤心时[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
