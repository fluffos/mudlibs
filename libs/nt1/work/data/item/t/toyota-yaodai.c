// SN:mG]lj6SIPH^lUQm8
// ITEM Made by player(曰曰:toyota) /data/item/t/toyota-yaodai.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Mar 19 22:05:20 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m腰带[2;37;0m", ({ "yaodai" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
腰带缘上刻着一行小字：曰曰(toyota)
");
	set("value", 2100000);
	set("point", 192);
	set("material", "silk");
	set("wear_msg", "[33m$N系上一根$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N解下一根$n[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
