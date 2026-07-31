// SN:R7A@D?fc>EYXPMCO
// ITEM Made by player(叶多多:ydd) /data/item/y/ydd-lunhui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jan 16 22:15:14 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m六道轮回[2;37;0m", ({ "lunhui" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;31m帝败神农之初，三界乱，刑天，蚩尤，共工借乱起，帝斩之，共工不绝触不周而忘，山崩。女娲采石补天，三界平。帝思天下，取共工脊骨炼化兵，囚蚩尤，刑天凶灵于内，以三滴心血喂，天地动容，血痕化字曰：六道轮回[2;37;0m
剑柄上刻着一行小字：叶多多(ydd)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
