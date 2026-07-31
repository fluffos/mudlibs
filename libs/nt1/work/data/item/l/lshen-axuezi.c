// SN:?gD=T?lI]^c2K79:
// ITEM Made by player(洛神:lshen) /data/item/l/lshen-axuezi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Nov 12 01:35:22 2003
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[33m阿尔法靴子[2;37;0m", ({ "axuezi" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
靴子缘上刻着一行小字：洛神(lshen)
");
	set("value", 2100000);
	set("point", 88);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[2;37;0m[33m阿尔法靴子[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[2;37;0m[33m阿尔法靴子[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
