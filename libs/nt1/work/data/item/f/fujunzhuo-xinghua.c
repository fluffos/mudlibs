// SN:di1hO4bJYZ=[P>]X
// ITEM Made by player(傅君婥:fujunzhuo) /data/item/f/fujunzhuo-xinghua.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Apr  8 21:19:17 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m明朝深巷卖杏花[2;37;0m", ({ "xinghua" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;32m一把奇奇怪怪的剑，剑刃居然带有一种诡异的弧度，就像是惊鸿掠过夕阳一般，完美的令人心寒。
据说此剑是[1;31m魔教教主[1;32m手中那把[1;31m小楼一夜听春雨[1;32m的孪生剑。[2;37;0m
剑柄上刻着一行小字：傅君婥(fujunzhuo)
");
	set("value", 2100000);
	set("point", 346);
	set("material", "magic stone");
	set("wield_msg", "[1;31m$N向着天空念了一句古老而苍凉的咒语，天地间卷过一层如有似无的雾气，雾气散过之后，$N手上便多了一把$n[1;31m。[2;37;0m\n");
	set("unwield_msg", "[1;31m$N再一次吟唱起那首苍凉的咒语，仿佛来自远古诸神的祝福，手中柔光闪过，$n[1;31m已消失在空气里。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
