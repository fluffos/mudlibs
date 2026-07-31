// SN:6PfCcOFoN]lc>f_S
// ITEM Made by player(段心:bug) /data/item/b/bug-piaoxue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 24 14:01:09 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("飘雪[2;37;0m", ({ "piaoxue" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一张护甲。
护甲缘上刻着一行小字：段心(bug)
");
	set("value", 2100000);
	set("point", 289);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备飘雪[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了飘雪[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
