// SN:]]G5OF:4J<D_7dS@
// ITEM Made by player(白云:sau) /data/item/s/sau-mystrike.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jan 14 15:58:55 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m铁掌[2;37;0m", ({ "mystrike" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：白云(sau)
");
	set("value", 2100000);
	set("point", 346);
	set("material", "magic stone");
	set("wear_msg", "[1;31m$N两手一扬，只听丝丝作响，空中腾起一股雾气，弥漫四周。$n[1;31m已然戴在手上。[2;37;0m\n");
	set("remove_msg", "[1;35m$N缓缓的将$n[1;35m脱了下来，收入怀中。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
