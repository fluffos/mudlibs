// SN:^j>f5k0F4bITFdL`
// ITEM Made by player(慕容恪:bushiwo) /data/item/b/bushiwo-finger.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Dec 14 23:50:48 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m琥珀神环[2;37;0m", ({ "finger" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
这个指环看上去手工非常精良。[2;37;0m
指套缘上刻着一行小字：慕容恪(bushiwo)
");
	set("value", 2100000);
	set("point", 250);
	set("material", "magic stone");
	set("wear_msg", "[1;33m$N戴上一个$n[1;33m。[2;37;0m\n");
	set("remove_msg", "[1;33m$N将$n[1;33m从指上取下。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/finger", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
