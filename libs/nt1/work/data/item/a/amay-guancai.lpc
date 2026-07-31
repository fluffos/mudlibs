// SN:]X9^:KOm9a5\<bEf
// ITEM Made by player(无头女尸:amay) /data/item/a/amay-guancai.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Oct 12 02:47:08 2004
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("棺材[2;37;0m", ({ "guancai" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[37m精铁[2;37;0m炼制而成的一根杖。
[1;32m这是一把快烂了的木头[2;37;0m
杖柄上刻着一行小字：无头女尸(amay)
");
	set("value", 700000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;31m只听“嗖”的一声，你手上多了一块烂木头[2;37;0m\n");
	set("unwield_msg", "[1;35m往地上一扔，说道：“妈的，坏的不去，新的不来”[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
