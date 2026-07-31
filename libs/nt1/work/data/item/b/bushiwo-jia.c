// SN:4PIPB7Th8?>[U:cD
// ITEM Made by player(慕容恪:bushiwo) /data/item/b/bushiwo-jia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Dec 14 02:00:23 2003
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m黄金甲[2;37;0m", ({ "jia" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一张护甲。
这件护甲上满是斑斑驳驳的刀剑之痕，看来跟随它的主人经历了不少的江湖风云。[2;37;0m
护甲缘上刻着一行小字：慕容恪(bushiwo)
");
	set("value", 2100000);
	set("point", 200);
	set("material", "magic stone");
	set("wear_msg", "[33m$N穿上一件$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N将$n[33m脱了下来。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
