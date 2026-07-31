// SN:<SZ;3VPCT`N\Q4M6
// ITEM Made by player(钟情:cookie) /data/item/c/cookie-asdf.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jul 28 02:31:45 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("冰冻之心[2;37;0m", ({ "asdf" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
冰冷冰冷冰冷的[2;37;0m
剑柄上刻着一行小字：钟情(cookie)
");
	set("value", 2100000);
	set("point", 178);
	set("material", "magic stone");
	set("wield_msg", "冰冷[2;37;0m\n");
	set("unwield_msg", "暖意[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
