// SN:Q@a<19>\RT52H3b;
// ITEM Made by player(猎人:hunterx) /data/item/h/hunterx-qse.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 30 16:32:45 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[36m小楼一夜听春雨[2;37;0m", ({ "qse" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
指套缘上刻着一行小字：猎人(hunterx)
");
	set("value", 2100000);
	set("point", 694);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[2;37;0m[36m小楼一夜听春雨[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[2;37;0m[36m小楼一夜听春雨[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);

	setup();
}

string long() { return query("long") + item_long(); }
