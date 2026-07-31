// SN:R48LVXX2=f]89BK<
// ITEM Made by player(蚂蚁:satyr) /data/item/s/satyr-satyrsd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jul  4 11:10:26 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m超级倚天剑[2;37;0m", ({ "satyrsd" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：蚂蚁(satyr)
");
	set("value", 2100000);
	set("point", 402);
	set("material", "magic stone");
	set("wield_msg", "[1;31m我杀杀杀[2;37;0m\n");
	set("unwield_msg", "[1;31m我下下下[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
