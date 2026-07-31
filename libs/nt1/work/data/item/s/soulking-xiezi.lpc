// SN:7Z6`=M>0UgGm9lNJ
// ITEM Made by player(杨云:soulking) /data/item/s/soulking-xiezi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep 13 22:16:01 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("碎心的鞋子[2;37;0m", ({ "xiezi" }));
	set_weight(1080);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[33m乌金丝[2;37;0m炼制而成的一双靴子。
平凡的物件必有不平凡之处[2;37;0m
靴子缘上刻着一行小字：杨云(soulking)
");
	set("value", 1500000);
	set("point", 28);
	set("material", "silk");
	set("wear_msg", "暗淡的悠光闪过你以装备完成[2;37;0m\n");
	set("remove_msg", "火焰般的白光闪过你以取下装备[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
