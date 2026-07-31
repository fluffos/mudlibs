// SN:U58?S\WSlnTZJn>G
// ITEM Made by player(段仙:sleep) /data/item/s/sleep-duan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 17 10:35:33 2004
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m断刀[2;37;0m", ({ "duan" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把刀。
[1;31m伤心人，刀也伤心[2;37;0m
刀柄上刻着一行小字：段仙(sleep)
");
	set("value", 2100000);
	set("point", 393);
	set("material", "magic stone");
	set("wield_msg", "[1;31m伤心人，刀也伤心[2;37;0m\n");
	set("unwield_msg", "[1;31m无心人[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
