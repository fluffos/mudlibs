// SN:6D3N:gAcP<TF0?Io
// ITEM Made by player(太子:taizi) /data/item/t/taizi-kkxa.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Feb 29 18:24:38 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m风魔手里剑[2;37;0m", ({ "kkxa" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;31m忍术风之刃－叶鬼[1;37m『[1;31m风魔手里剑[1;37m』[2;37;0m
剑柄上刻着一行小字：太子(taizi)
");
	set("value", 2100000);
	set("point", 390);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
