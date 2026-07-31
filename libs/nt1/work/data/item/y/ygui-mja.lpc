// SN:`NfKQE_A@E4lRJ7^
// ITEM Made by player(夜鬼:ygui) /data/item/y/ygui-mja.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jun 24 18:15:25 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m奕云轩[2;37;0m", ({ "mja" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;33m传说中由一位武功极了得的人用了七七四十九日的内力而铸成的。[2;37;0m
铁掌缘上刻着一行小字：夜鬼(ygui)
");
	set("value", 2100000);
	set("point", 480);
	set("material", "magic stone");
	set("wear_msg", "[1;37m$N[1;37m心中的正气突然上升，有一种$N[1;37m从来未感觉过的热力，$N[1;37m发觉$n[1;37m就在$N手里。[2;37;0m\n");
	set("remove_msg", "[1;37m$N一反手就将$n[1;37m没入腰间，旁人也看不清楚。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
