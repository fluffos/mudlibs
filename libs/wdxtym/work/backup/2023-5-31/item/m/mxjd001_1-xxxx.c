// ITEM Made by player(天辰夜皇:mxjd001_1) /data/item/m/mxjd001_1-xxxx.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Mar 26 15:29:48 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m青[1;32m莲[1;36m剑[2;37;0m", ({ "xxxx" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;31m真龙[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：天辰夜皇(mxjd001_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;35m凤兮凤兮归故乡，遨游四海求其凰。[2;37;0m\n");
	set("unwield_msg", "[1;36m永生不过是场幻梦，唯吾所爱不朽。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
