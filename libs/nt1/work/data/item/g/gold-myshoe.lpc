// SN:9>bXdE=RYZ3OYn?c
// ITEM Made by player(蓝魔:gold) /data/item/g/gold-myshoe.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Sep 24 15:36:40 2003
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m铁蹄[2;37;0m", ({ "myshoe" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
[1;32m一双踏不破的铁蹄！！[2;37;0m
靴子缘上刻着一行小字：蓝魔(gold)
");
	set("value", 2100000);
	set("point", 74);
	set("material", "silk");
	set("wear_msg", "[1;31m铁蹄踏死泥潭小人，小心啦！[2;37;0m\n");
	set("remove_msg", "[1;31m算啦，踩死人可不好！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
