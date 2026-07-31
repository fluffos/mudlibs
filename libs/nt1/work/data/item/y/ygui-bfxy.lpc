// SN:L\k@6bTaIcfYKl\h
// ITEM Made by player(夜鬼:ygui) /data/item/y/ygui-bfxy.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May 15 13:10:07 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m冰封雪影[2;37;0m", ({ "bfxy" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[37m著名的魔掌。精铁加特殊材料虾制而成，掌身有无数极细小的孔眼，毒药便渗入在其中。[2;37;0m
铁掌缘上刻着一行小字：夜鬼(ygui)
");
	set("value", 2100000);
	set("point", 431);
	set("material", "magic stone");
	set("wear_msg", "[1;37m$N手中突然清凉之极，原来$n[1;37m已在你手中。[2;37;0m\n");
	set("remove_msg", "[1;37m$N的掌心突然传出一股暖流，原来$n[1;37m已返回你的腰间。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
