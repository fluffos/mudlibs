// ITEM Made by player(渡狱:wang64218_1) /data/item/w/wang64218_1-tdxiao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar 21 23:25:28 2023
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m天[30m帝[2;37;0m萧[2;37;0m", ({ "tdxiao" }));
	set_weight(150);
	set("item_make", 1);
	set("unit", "支");
	set("long", "这是由[1;37m世界[2;37;0m炼制而成的一支箫。
箫柄上刻着一行小字：渡狱(wang64218_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一支[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
