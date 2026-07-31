// SN:l?nJ91LVQ6B8mO9N
// ITEM Made by player(慕容一:gege) /data/item/g/gege-gcloth.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Nov 14 23:26:05 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m黑龙战甲[2;37;0m", ({ "gcloth" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
[1;32m纹着黑龙的古战甲[2;37;0m
战衣缘上刻着一行小字：慕容一(gege)
");
	set("value", 2100000);
	set("point", 132);
	set("material", "silk");
	set("wear_msg", "[1;31m一道黑龙光，直冲霄汉[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;32m黑龙战甲[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
