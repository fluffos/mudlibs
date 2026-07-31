// SN:1h3EUgl4XX4Pjo5^
// ITEM Made by player(慕容痴:huo) /data/item/h/huo-feng.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 15 16:43:46 2004
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m红尘渡[2;37;0m", ({ "feng" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把刀。
[1;33m半生干戈，皆由它。[2;37;0m
刀柄上刻着一行小字：慕容痴(huo)
");
	set("value", 2100000);
	set("point", 218);
	set("material", "magic stone");
	set("wield_msg", "[1;32m快意恩怨，生不悔。[2;37;0m\n");
	set("unwield_msg", "[1;31m风息烟灭，红尘渡。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
