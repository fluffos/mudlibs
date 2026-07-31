// ITEM Made by player(等等:a15976738848_1) /data/item/a/a15976738848_1-wuyi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Mar 19 23:27:39 2023
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("无衣[2;37;0m", ({ "wuyi" }));
	set_weight(1000);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m世界[2;37;0m炼制而成的一件战衣。
岂曰无衣与子同裳[2;37;0m
战衣缘上刻着一行小字：等等(a15976738848_1)
");
	set("value", 200100000);
	set("point", 10000);
	set("material", "silk");
	set("wear_msg", "岂曰无衣与子同裳[2;37;0m\n");
	set("remove_msg", "真的没有衣服[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
