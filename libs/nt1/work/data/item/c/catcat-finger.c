// SN:_kG1?2Jg0D<`m@]^
// ITEM Made by player(段吟雪:catcat) /data/item/c/catcat-finger.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jan  6 21:21:12 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m天魔指[2;37;0m", ({ "finger" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
指套缘上刻着一行小字：段吟雪(catcat)
");
	set("value", 2100000);
	set("point", 217);
	set("material", "magic stone");
	set("wear_msg", "[1;37m暗运内力，只见一道白芒闪过，你手中已无声无息地多了一副天魔指。[2;37;0m\n");
	set("remove_msg", "[1;37m天魔指自你掌中飞起，在半空中一转，「唰」地消失不见。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
