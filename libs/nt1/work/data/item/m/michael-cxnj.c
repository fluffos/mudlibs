// SN:R88LT7j`ec=oEiAX
// ITEM Made by player(行香子:michael) /data/item/m/michael-cxnj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Oct 12 14:25:05 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m武陵春[2;37;0m", ({ "cxnj" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;32m武陵春[2;37;0m
剑柄上刻着一行小字：行香子(michael)
");
	set("value", 2100000);
	set("point", 224);
	set("material", "magic stone");
	set("wield_msg", "[1;32m风住尘香花已尽，日晚倦梳头。物是人非事事休，欲语泪先流。[2;37;0m\n");
	set("unwield_msg", "[1;32m闻说双溪春尚好，也拟泛轻舟。只恐双溪舴艋舟，载不动、许多愁。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
