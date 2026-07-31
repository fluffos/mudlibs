// SN:H`6gL?mKb<gTf\Vh
// ITEM Made by player(澄段:six) /data/item/s/six-fing.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Dec  5 16:08:30 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m血魔指[2;37;0m", ({ "fing" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
[1;31m传说中血魔的武器[2;37;0m
指套缘上刻着一行小字：澄段(six)
");
	set("value", 2100000);
	set("point", 146);
	set("material", "magic stone");
	set("wear_msg", "[1;31m穿上血魔指[2;37;0m\n");
	set("remove_msg", "[1;31m脱下血魔指[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/finger", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
