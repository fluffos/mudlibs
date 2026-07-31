// SN:FHEh3QW[ZhlCm16k
// ITEM Made by player(孤独的云:lting) /data/item/l/lting-sworda.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Oct  5 16:40:09 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m玄铁剑[2;37;0m", ({ "sworda" }));
	set_weight(7500);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[37m上古寒铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：孤独的云(lting)
");
	set("value", 1500000);
	set("point", 559);
	set("material", "steel");
	set("wield_msg", "[1;33m$N嗡的一声从背后抽出$n[1;33m，但见寒气逼人，杀雾迷茫，\n方圆之内轰然雷声滚滚，肃杀万分。[2;37;0m\n");
	set("unwield_msg", "[34m$N将$n[34m插回肩后，杀气顿减。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
