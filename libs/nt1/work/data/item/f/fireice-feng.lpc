// SN:M:`b@36_c0;mDV;h
// ITEM Made by player(水灵:fireice) /data/item/f/fireice-feng.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Nov 24 09:43:22 2003
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m风神[2;37;0m", ({ "feng" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
[1;36m它是传说中风神的化身[2;37;0m
头盔缘上刻着一行小字：水灵(fireice)
");
	set("value", 2100000);
	set("point", 108);
	set("material", "magic stone");
	set("wear_msg", "[1;31m一阵神风吹过，神盔已经装备了[2;37;0m\n");
	set("remove_msg", "[1;31m一阵神风吹过，神盔卸下[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
