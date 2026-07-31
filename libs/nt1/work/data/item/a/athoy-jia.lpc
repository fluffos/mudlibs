// SN:LB6:JjDAE4kg7T<b
// ITEM Made by player(神游:athoy) /data/item/a/athoy-jia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jun 30 17:08:28 2003
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m穿云甲[2;37;0m", ({ "jia" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一张护甲。
[1;37m一件护甲[2;37;0m
护甲缘上刻着一行小字：神游(athoy)
");
	set("value", 2100000);
	set("point", 176);
	set("material", "magic stone");
	set("wear_msg", "[1;37m穿上穿云甲[2;37;0m\n");
	set("remove_msg", "[1;37m脱下穿云甲[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
