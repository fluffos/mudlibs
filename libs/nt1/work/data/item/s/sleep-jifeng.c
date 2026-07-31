// SN:ll>E4`4^JjX2>I:b
// ITEM Made by player(段仙:sleep) /data/item/s/sleep-jifeng.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jun 10 22:22:09 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m疾风[2;37;0m", ({ "jifeng" }));
	set_weight(3600);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双靴子。
靴子缘上刻着一行小字：段仙(sleep)
");
	set("value", 2100000);
	set("point", 146);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;32m疾风[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;32m疾风[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
