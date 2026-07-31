// SN:hLMOPU2^Qk;Ro05j
// ITEM Made by player(神游:athoy) /data/item/a/athoy-toukui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jul  5 06:51:42 2003
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m避云盔[2;37;0m", ({ "toukui" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
[1;37m一顶头盔[2;37;0m
头盔缘上刻着一行小字：神游(athoy)
");
	set("value", 2100000);
	set("point", 110);
	set("material", "magic stone");
	set("wear_msg", "[1;37m戴上避云盔[2;37;0m\n");
	set("remove_msg", "[1;37m脱下避云盔[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
