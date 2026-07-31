// ITEM Made by player(唐霍去病:mgs66573_1) /data/item/m/mgs66573_1-lianyu.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 14:22:38 2023
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("炼狱[2;37;0m", ({ "lianyu" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
战衣缘上刻着一行小字：唐霍去病(mgs66573_1)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备炼狱[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了炼狱[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
