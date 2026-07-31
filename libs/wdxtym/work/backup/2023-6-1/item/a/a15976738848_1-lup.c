// ITEM Made by player(等等:a15976738848_1) /data/item/a/a15976738848_1-lup.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Mar 16 14:06:25 2023
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("先天芦蓬[2;37;0m", ({ "lup" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;37m世界[2;37;0m炼制而成的一张护甲。
[33m道心不灭，[1;32m芦蓬不毁。
[1;36m周而复始，循环往复
[1;31m宇宙灭而我不灭！寰宇寂而我不息！[2;37;0m
护甲缘上刻着一行小字：等等(a15976738848_1)
");
	set("value", 200100000);
	set("point", 17600);
	set("material", "silk");
	set("wear_msg", "[33m道心不灭，[1;32m芦蓬不毁。\n[1;36m周而复始，循环往复\n[1;31m宇宙灭而我不灭！寰宇寂而我不息！[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了先天芦蓬[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
