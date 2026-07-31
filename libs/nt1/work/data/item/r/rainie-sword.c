// SN:anN`DCYUTo85@f[L
// ITEM Made by player(秦梦遥:rainie) /data/item/r/rainie-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jul 27 11:10:47 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m七[1;31m龙[1;36m剑[2;37;0m", ({ "sword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：秦梦遥(rainie)
");
	set("value", 2100000);
	set("point", 841);
	set("material", "magic stone");
	set("wield_msg", "[1;34m天地突然一片混沌，[1;35m七龙剑[1;34m已来到了梦遥的手中。[2;37;0m\n");
	set("unwield_msg", "[1;33m天地豁然开朗，[1;32m七龙剑[1;33m已消失在云彩之颠。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
