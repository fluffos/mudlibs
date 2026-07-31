// SN:d;75bFFkK@eiYiJm
// ITEM Made by player(段子羽:windsmile) /data/item/w/windsmile-xsword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 23 16:58:51 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m小楼一夜听春雨[2;37;0m", ({ "xsword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;33m这把是世间少有的好剑，剑身青光闪闪。[2;37;0m
剑柄上刻着一行小字：段子羽(windsmile)
");
	set("value", 2100000);
	set("point", 879);
	set("material", "magic stone");
	set("wield_msg", "[36m$N手中突然清凉之极，原来$n[36m已在你手中。[2;37;0m\n");
	set("unwield_msg", "[36m$N的掌心突然传出一股暖流，原来$n[36m已返回你的腰间。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
