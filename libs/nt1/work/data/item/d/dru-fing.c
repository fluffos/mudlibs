// SN:5\f\];G`Yh966gY7
// ITEM Made by player(太极:dru) /data/item/d/dru-fing.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May 25 04:12:12 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m风云指[2;37;0m", ({ "fing" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
[1;36m风云指出，风起云动[2;37;0m
指套缘上刻着一行小字：太极(dru)
");
	set("value", 2100000);
	set("point", 212);
	set("material", "magic stone");
	set("wear_msg", "[1;36m风云指出，风起云动[2;37;0m\n");
	set("remove_msg", "[1;36m风云指出，风起云动[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
