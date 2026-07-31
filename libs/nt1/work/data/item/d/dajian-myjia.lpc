// SN:2aQlYNhGc\Nd@YJ@
// ITEM Made by player(步小嘉:dajian) /data/item/d/dajian-myjia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Sep  4 15:12:06 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("烈火甲[2;37;0m", ({ "myjia" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一张护甲。
护甲缘上刻着一行小字：步小嘉(dajian)
");
	set("value", 2100000);
	set("point", 176);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备烈火甲[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了烈火甲[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
