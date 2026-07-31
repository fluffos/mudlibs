// SN:?JOLK8bKM^YAa[EU
// ITEM Made by player(李太白:libai) /data/item/l/libai-jia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jan  2 14:11:32 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m宝[1;31m甲[2;37;0m", ({ "jia" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一张护甲。
护甲缘上刻着一行小字：李太白(libai)
");
	set("value", 2100000);
	set("point", 190);
	set("material", "silk");
	set("wear_msg", "[1;32m$N将$n[1;32m穿在身上。[2;37;0m\n");
	set("remove_msg", "[1;36m$N将$n[1;36m从身上脱下。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
