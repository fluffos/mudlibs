// SN:C7hXjL?Jd=BnkVBK
// ITEM Made by player(猎人:hunterx) /data/item/h/hunterx-dja.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Apr 16 15:07:39 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m小李飞刀[2;37;0m", ({ "dja" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;37m这是一把锋利的宝刀，刀柄上用金丝银丝镶著一钩眉毛月之形。[2;37;0m
剑柄上刻着一行小字：猎人(hunterx)
");
	set("value", 2100000);
	set("point", 414);
	set("material", "magic stone");
	set("wield_msg", "[1;37m只见冷森森的一道青光激射而出。寒光闪烁不定，[1;32m小李飞刀[1;37m已入$N的手里！[2;37;0m\n");
	set("unwield_msg", "[1;37m小李飞刀不见了。。。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
