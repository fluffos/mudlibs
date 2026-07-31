// SN:k4K27olhWJ\FKdVf
// ITEM Made by player(段剑:swordmo) /data/item/s/swordmo-liumai.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep  8 18:39:43 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m六脉[1;33m神剑[2;37;0m", ({ "liumai" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
这是一本[1;36m武功秘籍[2;37;0m，它记载了大理[1;36m天龙寺[2;37;0m的镇寺绝学[1;36m六脉神剑[2;37;0m
指套缘上刻着一行小字：段剑(swordmo)
");
	set("value", 2100000);
	set("point", 179);
	set("material", "magic stone");
	set("wear_msg", "[1;32m$N[2;37;0m从身上拿出一本[1;31m六脉[1;33m神剑[2;37;0m，聚精会神的读了起来[2;37;0m\n");
	set("remove_msg", "[1;32m$N[2;37;0m把[1;31m六脉[1;33m神剑[2;37;0m收了起来，而且盯着你看了一会儿[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
