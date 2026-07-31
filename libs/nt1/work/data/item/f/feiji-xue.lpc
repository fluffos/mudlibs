// SN:]_61Hfo5\<<BCi6l
// ITEM Made by player(飞机:feiji) /data/item/f/feiji-xue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug  3 13:23:40 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m黑凤凰之靴[2;37;0m", ({ "xue" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
靴子缘上刻着一行小字：飞机(feiji)
");
	set("value", 2100000);
	set("point", 112);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;36m黑凤凰之靴[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;36m黑凤凰之靴[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
