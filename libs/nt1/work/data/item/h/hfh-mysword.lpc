// SN:e0ONNfY2h9gCGBQ2
// ITEM Made by player(花非花:hfh) /data/item/h/hfh-mysword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Dec 27 04:10:38 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m玄铁剑[2;37;0m", ({ "mysword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：花非花(hfh)
");
	set("value", 2100000);
	set("point", 238);
	set("material", "magic stone");
	set("wield_msg", "[1;33m$N嗡的一声从背后抽出$n[1;33m，但见寒气逼人，杀雾迷茫，\n方圆之内轰然雷声滚滚，肃杀万分。[2;37;0m\n");
	set("unwield_msg", "[1;34m$N反手将$n[1;34m插回肩后，杀气顿减。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
