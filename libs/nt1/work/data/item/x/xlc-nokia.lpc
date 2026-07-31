// SN:]\]=oHmZi:VTRG\6
// ITEM Made by player(向来痴:xlc) /data/item/x/xlc-nokia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Sep 10 08:26:20 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m诺基亚[2;37;0m", ({ "nokia" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
重八公斤，长二十厘米，黑色[2;37;0m
铁掌缘上刻着一行小字：向来痴(xlc)
");
	set("value", 2100000);
	set("point", 216);
	set("material", "magic stone");
	set("wear_msg", "滴玲玲，电话响了，是村东头的王木匠打来的[2;37;0m\n");
	set("remove_msg", "他妈的，问老子借钱，不给。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
