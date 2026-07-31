// SN:O?DPBLPmLgC9Sc@M
// ITEM Made by player(冥焱枫:wuki) /data/item/w/wuki-wuj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Nov  7 01:52:10 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m冥焱[1;36m枪[1;33m刃[2;37;0m", ({ "wuj" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;31m这是一柄未来世界的兵器，[1;33m远可当离子枪使用，[1;36m可发出高强度离子射线，[1;37m近可当高等离子剑，[1;35m锋得无比！[2;37;0m
剑柄上刻着一行小字：冥焱枫(wuki)
");
	set("value", 2100000);
	set("point", 135);
	set("material", "magic stone");
	set("wield_msg", "[1;31m临、兵、[1;33m斗、者、[1;34m皆、阵、[1;35m列、[1;36m在、[1;37m前！[32m冥焱！[2;37;0m\n");
	set("unwield_msg", "[31m体、精、[33m气、神、[34m人、生、[35m灭、[36m幻、[37m无！[1;32m散！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
