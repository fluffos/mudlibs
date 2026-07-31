// SN:K:g\^Bd78aaXchj_
// ITEM Made by player(悟空:www) /data/item/w/www-wss.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Apr  7 23:49:46 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m如意[1;33m金箍棒[2;37;0m", ({ "wss" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;37m寰宇天晶[2;37;0m炼制而成的一柄剑。
此棒原是大禹治水之时，定江海浅深的一个定子，位于东海海藏，称为定海神针。
两头是两个金箍，中间乃一段乌铁。
紧挨箍有镌成的一行字，唤做[1;37m如意[1;33m金箍棒[2;37;0m。
重一万三千五百斤。[2;37;0m
剑柄上刻着一行小字：悟空(www)
");
	set("value", 4100000);
	set("point", 1570);
	set("material", "tian jing");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
