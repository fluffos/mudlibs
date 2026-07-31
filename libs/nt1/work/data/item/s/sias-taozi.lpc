// SN:OO_LW4U`mZCcV`oB
// ITEM Made by player(段克邪:sias) /data/item/s/sias-taozi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Aug  6 20:48:01 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m安全套[2;37;0m", ({ "taozi" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一张护甲。
[1;31m干的时候戴的[2;37;0m
护甲缘上刻着一行小字：段克邪(sias)
");
	set("value", 2100000);
	set("point", 156);
	set("material", "silk");
	set("wear_msg", "[1;31m要干了，戴上一个安全套[2;37;0m\n");
	set("remove_msg", "[1;31m不干了，脱下一个安全套[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
