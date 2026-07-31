// SN::\a95mV[H`5giX7H
// ITEM Made by player(段克邪:sias) /data/item/s/sias-yili.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug  3 23:06:50 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m依理逆斯[2;37;0m", ({ "yili" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
[1;31m生化装备，升级无限[2;37;0m
指套缘上刻着一行小字：段克邪(sias)
");
	set("value", 2100000);
	set("point", 186);
	set("material", "magic stone");
	set("wear_msg", "[1;31m神光一指\n淅沥哗啦[2;37;0m\n");
	set("remove_msg", "[1;31m淅沥哗啦\n神光一指[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
