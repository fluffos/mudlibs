// SN:E^k11W4aJ_lSUdO`
// ITEM Made by player(神游:athoy) /data/item/a/athoy-flyc.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Dec  7 01:59:21 2003
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m诺基亚千里行[2;37;0m", ({ "flyc" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
靴子缘上刻着一行小字：神游(athoy)
");
	set("value", 2100000);
	set("point", 169);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;34m诺基亚千里行[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;34m诺基亚千里行[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
