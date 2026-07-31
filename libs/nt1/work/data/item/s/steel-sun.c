// SN:eFXMh[<\UV?WDc2^
// ITEM Made by player(魔影:steel) /data/item/s/steel-sun.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Nov 12 01:09:41 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("日月光辉[2;37;0m", ({ "sun" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
天地之精华为其血脉，日月之光辉是其灵气[2;37;0m
剑柄上刻着一行小字：魔影(steel)
");
	set("value", 2100000);
	set("point", 176);
	set("material", "magic stone");
	set("wield_msg", "天地之精华[2;37;0m\n");
	set("unwield_msg", "日月之光辉[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
