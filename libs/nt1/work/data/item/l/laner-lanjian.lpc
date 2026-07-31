// SN:ZRJ`00:T26;2o5di
// ITEM Made by player(段蓝儿:laner) /data/item/l/laner-lanjian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Nov 12 13:57:50 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m小楼一夜听春雨[2;37;0m", ({ "lanjian" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;32m小楼一夜听春雨[2;37;0m
剑柄上刻着一行小字：段蓝儿(laner)
");
	set("value", 2100000);
	set("point", 268);
	set("material", "magic stone");
	set("wield_msg", "[1;32m小楼一夜听春雨[2;37;0m\n");
	set("unwield_msg", "[1;32m小楼一夜听春雨[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
