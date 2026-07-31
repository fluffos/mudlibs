// SN:?`2WA6T?DP1ea]Cl
// ITEM Made by player(胡小僧:loop) /data/item/l/loop-xue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Nov 18 11:22:24 2003
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m皮靴[2;37;0m", ({ "xue" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
看上去这双靴子质量非常好。[2;37;0m
靴子缘上刻着一行小字：胡小僧(loop)
");
	set("value", 2100000);
	set("point", 96);
	set("material", "silk");
	set("wear_msg", "[33m$N穿上一双$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N将$n[33m脱了下来。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/dodge", apply_armor() / 10 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
