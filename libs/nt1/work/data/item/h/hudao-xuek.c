// SN:naO^3Y8GF=KIZPlj
// ITEM Made by player(杀人少尉:hudao) /data/item/h/hudao-xuek.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 30 03:19:30 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("化血[2;37;0m", ({ "xuek" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
化血一出，人头落地[2;37;0m
铁掌缘上刻着一行小字：杀人少尉(hudao)
");
	set("value", 2100000);
	set("point", 161);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备化血[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了化血[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
