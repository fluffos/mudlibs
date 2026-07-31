// SN:3QT69I7mVBOl=SaX
// ITEM Made by player(欧阳明月:xunfei) /data/item/x/xunfei-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Oct  1 12:02:22 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m爱神丘比特之剑[2;37;0m", ({ "jian" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;37m这是小爱神的玩具[2;37;0m
剑柄上刻着一行小字：欧阳明月(xunfei)
");
	set("value", 2100000);
	set("point", 342);
	set("material", "magic stone");
	set("wield_msg", "[1;37m$N拿出来爱神之剑，日月光华尽在其间。。[2;37;0m\n");
	set("unwield_msg", "[1;37m$N收回了手中的爱神之剑，风月了然无痕。。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
