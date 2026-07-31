// SN:?`=ELKnYXHGToLjh
// ITEM Made by player(段克邪:sias) /data/item/s/sias-caosheng.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Aug  5 23:06:02 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m草绳[2;37;0m", ({ "caosheng" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
一根由烂草编织而成的绳子，穷苦人家的腰带[2;37;0m
腰带缘上刻着一行小字：段克邪(sias)
");
	set("value", 2100000);
	set("point", 74);
	set("material", "silk");
	set("wear_msg", "[1;32m系上一根烂草绳[2;37;0m\n");
	set("remove_msg", "[1;32m解下一根烂草绳[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
