// SN:C>o>_kh46>F5@`\g
// ITEM Made by player(段枫:jump) /data/item/j/jump-shenmo.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jun 19 22:22:41 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m六指神魔[2;37;0m", ({ "shenmo" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
指套缘上刻着一行小字：段枫(jump)
");
	set("value", 2100000);
	set("point", 194);
	set("material", "magic stone");
	set("wear_msg", "[1;35m$N拿出六指神魔套在手上，顿时天昏地暗，一片飞沙走石。[2;37;0m\n");
	set("remove_msg", "[1;35m$N取下六指神魔，天地得以重见阳光，人人长舒了一口气。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/finger", 10);

	setup();
}

string long() { return query("long") + item_long(); }
