// SN:h6fk[hoeZH`3V?^h
// ITEM Made by player(啊勇:dhl) /data/item/d/dhl-eee.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Apr 25 18:23:53 2004
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m防毒[1;31m面具[2;37;0m", ({ "eee" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
[1;32m正宗的德过原厂货[2;37;0m
头盔缘上刻着一行小字：啊勇(dhl)
");
	set("value", 2100000);
	set("point", 61);
	set("material", "magic stone");
	set("wear_msg", "[1;35m又饥又渴，觉得自己快要死了[2;37;0m\n");
	set("remove_msg", "[1;37m真想大吃一顿[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
