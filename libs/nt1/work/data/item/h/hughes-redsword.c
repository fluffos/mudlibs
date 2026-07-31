// SN:iQHP5^KS]Ql1O1IB
// ITEM Made by player(宇文成都:hughes) /data/item/h/hughes-redsword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Oct  1 11:06:54 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m火剑[2;37;0m", ({ "redsword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;33m一把滴[1;31m血[1;33m的剑[2;37;0m
剑柄上刻着一行小字：宇文成都(hughes)
");
	set("value", 2100000);
	set("point", 174);
	set("material", "magic stone");
	set("wield_msg", "[1;33m拔剑惊天地[2;37;0m\n");
	set("unwield_msg", "[1;31m收剑泣鬼神[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
