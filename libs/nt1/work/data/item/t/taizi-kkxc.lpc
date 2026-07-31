// SN:l5f9?47AiO;1Jj9B
// ITEM Made by player(太子:taizi) /data/item/t/taizi-kkxc.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Feb 29 18:30:53 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m双蛇相杀[2;37;0m", ({ "kkxc" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一张护甲。
护甲缘上刻着一行小字：太子(taizi)
");
	set("value", 2100000);
	set("point", 312);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;35m双蛇相杀[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;35m双蛇相杀[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
