// SN:0\KR?Xd2_j_5QL1<
// ITEM Made by player(啊勇:dhl) /data/item/d/dhl-qiang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Apr 24 22:15:10 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m尸魂[1;36m法[1;37m杖[2;37;0m", ({ "qiang" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;32m这是一把专门杀坏人的法杖[2;37;0m
剑柄上刻着一行小字：啊勇(dhl)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "[1;37m一道白光闪过坏人的头全被我砍下了[2;37;0m\n");
	set("unwield_msg", "[1;31m看什么啊[1;33m就是要你头落地[1;36m我不知道[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
