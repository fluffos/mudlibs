// SN:CDRNVKUGC`X5AMQV
// ITEM Made by player(唐五藏:tangwu) /data/item/t/tangwu-kui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Dec 13 21:24:45 2003
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m碧玉簪[2;37;0m", ({ "kui" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
看上去碧光殷殷，倒是一件不错的东东。[2;37;0m
头盔缘上刻着一行小字：唐五藏(tangwu)
");
	set("value", 2100000);
	set("point", 118);
	set("material", "magic stone");
	set("wear_msg", "[1;33m$N戴上一只$n[1;33m。[2;37;0m\n");
	set("remove_msg", "[1;33m$N将$n[1;33m摘了下来，收进怀里。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
