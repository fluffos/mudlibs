// SN:KhiMI3FHRYhk`Ceg
// ITEM Made by player(伯约:boyuezi) /data/item/b/boyuezi-bza.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jun  3 19:03:57 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31m轩辕之心[2;37;0m", ({ "bza" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
由上古轩辕之心所化的武器，据说威力超群。[2;37;0m
铁掌缘上刻着一行小字：伯约(boyuezi)
");
	set("value", 2100000);
	set("point", 276);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[2;37;0m[31m轩辕之心[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[2;37;0m[31m轩辕之心[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
