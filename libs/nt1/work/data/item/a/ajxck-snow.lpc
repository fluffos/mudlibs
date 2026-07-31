// SN:kkPQiNR6KljHBH<\
// ITEM Made by player(傲剑啸长空:ajxck) /data/item/a/ajxck-snow.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Sep 18 17:19:46 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m雪落之无声[2;37;0m", ({ "snow" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;35m雪花无声的落在了地上，不禁想起了和你在一起的甜蜜。[2;37;0m
剑柄上刻着一行小字：傲剑啸长空(ajxck)
");
	set("value", 2100000);
	set("point", 258);
	set("material", "magic stone");
	set("wield_msg", "[1;37m寒风凛冽，天空阴霾，天地已失去了往日的宁静。[2;37;0m\n");
	set("unwield_msg", "[1;37m风过了，云散了，天空不再阴霾，往昔的宁静与和平也接踵而至。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
