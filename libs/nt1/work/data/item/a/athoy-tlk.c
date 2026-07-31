// SN::XUWLhmReg3\`kDh
// ITEM Made by player(神游:athoy) /data/item/a/athoy-tlk.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Dec  7 01:52:28 2003
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[33m天龙盔[2;37;0m", ({ "tlk" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
头盔缘上刻着一行小字：神游(athoy)
");
	set("value", 2100000);
	set("point", 212);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[2;37;0m[33m天龙盔[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[2;37;0m[33m天龙盔[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
