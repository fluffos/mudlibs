// SN:OMonED8K@lSj[H5J
// ITEM Made by player(前世今生:samsara) /data/item/s/samsara-saae.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Apr 13 17:06:59 2004
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37m骷髅王冠[2;37;0m", ({ "saae" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
头盔缘上刻着一行小字：前世今生(samsara)
");
	set("value", 2100000);
	set("point", 387);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[2;37;0m[37m骷髅王冠[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[2;37;0m[37m骷髅王冠[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
