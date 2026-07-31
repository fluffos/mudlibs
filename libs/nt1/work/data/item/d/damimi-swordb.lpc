// SN:XAlHYGRH74hI>NF[
// ITEM Made by player(段晴:damimi) /data/item/d/damimi-swordb.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 31 08:29:33 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m寰宇天晶[2;37;0m", ({ "swordb" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;37m寰宇天晶[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：段晴(damimi)
");
	set("value", 4100000);
	set("point", 1601);
	set("material", "tian jing");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
