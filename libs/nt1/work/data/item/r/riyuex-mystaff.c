// SN:S6lgT][nF2=<nM;f
// ITEM Made by player(蓝魔之泪:riyuex) /data/item/r/riyuex-mystaff.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Oct 28 21:42:09 2003
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m蓝魔之杖[2;37;0m", ({ "mystaff" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一根杖。
[1;31m蓝魔的护身神杖[2;37;0m
杖柄上刻着一行小字：蓝魔之泪(riyuex)
");
	set("value", 2100000);
	set("point", 235);
	set("material", "magic stone");
	set("wield_msg", "[1;31m蓝魔无敌[2;37;0m\n");
	set("unwield_msg", "[1;31m蓝魔永远无敌[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
