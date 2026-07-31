// SN:VmRZOme<oeNenM2N
// ITEM Made by player(杨云:soulking) /data/item/s/soulking-kui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Sep 17 11:12:40 2004
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("碎心的头盔[2;37;0m", ({ "kui" }));
	set_weight(3750);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[37m上古寒铁[2;37;0m炼制而成的一顶头盔。
平凡的物件必有不平凡之处[2;37;0m
头盔缘上刻着一行小字：杨云(soulking)
");
	set("value", 1500000);
	set("point", 58);
	set("material", "steel");
	set("wear_msg", "∮暗淡的悠光闪过你以装备完成[2;37;0m\n");
	set("remove_msg", "∮火焰般的白光闪过你以取下装备[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
