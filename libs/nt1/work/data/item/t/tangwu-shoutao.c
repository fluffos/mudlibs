// SN:C1nBXkjkV_Dk^8OU
// ITEM Made by player(唐五藏:tangwu) /data/item/t/tangwu-shoutao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Dec 13 21:31:30 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m手套[2;37;0m", ({ "shoutao" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
看上去经历了多年的江湖厮杀，隐隐透出血光。[2;37;0m
铁掌缘上刻着一行小字：唐五藏(tangwu)
");
	set("value", 2100000);
	set("point", 236);
	set("material", "magic stone");
	set("wear_msg", "[1;33m$N将一双$n[1;33m戴在手上。[2;37;0m\n");
	set("remove_msg", "[1;33m$N将$n[1;33m除了下来，收进怀里。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
