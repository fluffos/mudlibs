// SN:aCnjTWdP6W>GSWJ2
// ITEM Made by player(武林争帝:wlzbiiii) /data/item/w/wlzbiiii-sworda.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Nov  8 09:36:43 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m龙纹剑[2;37;0m", ({ "sworda" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;37m传说中的[1;31m上古神剑[1;33m龙纹[2;37;0m
剑柄上刻着一行小字：武林争帝(wlzbiiii)
");
	set("value", 2100000);
	set("point", 318);
	set("material", "magic stone");
	set("wield_msg", "[1;32m$N[35m大喝一声[1;34m拔出了[1;31m上古神剑[1;33m龙纹[1;37m整个天地为之变色[2;37;0m\n");
	set("unwield_msg", "[1;32m$N[35m大喝一声[1;34m收回了[1;31m上古神剑[1;33m龙纹[1;37m整个天地恢复了颜色[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
