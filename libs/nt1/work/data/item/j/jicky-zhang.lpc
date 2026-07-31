// SN:Yo0j:]CM2Q7JScfQ
// ITEM Made by player(毛毛:jicky) /data/item/j/jicky-zhang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May 15 12:22:39 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m狂风掌[2;37;0m", ({ "zhang" }));
	set_weight(2025);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[37m精铁[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：毛毛(jicky)
");
	set("value", 700000);
	set("point", 49);
	set("material", "iron");
	set("wear_msg", "[33m$N[33m装备[1;37m狂风掌[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m狂风掌[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
