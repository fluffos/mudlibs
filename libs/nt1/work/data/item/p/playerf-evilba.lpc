// SN:@lmGkU5<3>[LQSD=
// ITEM Made by player(南宫无仁:playerf) /data/item/p/playerf-evilba.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Nov 11 18:37:53 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[34m恶魔之爪[2;37;0m", ({ "evilba" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[30m这是使用九幽恶魔的[34m恶魔厉爪[30m炼制，经过[1;31m恶魔之血[30m浸泡的带有诅咒的[34m恶魔之爪。[2;37;0m
剑柄上刻着一行小字：南宫无仁(playerf)
");
	set("value", 2100000);
	set("point", 278);
	set("material", "magic stone");
	set("wield_msg", "[1;31m$N从九幽深潭中抓出一只[34m恶魔之爪[1;31m拿在手里。[2;37;0m\n");
	set("unwield_msg", "[1;31m$N将[34m恶魔之爪[1;31m浸入九幽深潭。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
