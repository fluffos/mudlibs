// SN:O73ENQ]c:g_TgTSe
// ITEM Made by player(唐三藏:gangbj) /data/item/g/gangbj-zhang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Dec  8 01:30:34 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m手套[2;37;0m", ({ "zhang" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
看上去似乎是一双很普通的手套。[2;37;0m
铁掌缘上刻着一行小字：唐三藏(gangbj)
");
	set("value", 2100000);
	set("point", 291);
	set("material", "magic stone");
	set("wear_msg", "[1;31m$N双手往空中一探，一双$n[1;31m已经戴在手上。[2;37;0m\n");
	set("remove_msg", "[1;35m$N双手一晃，$n[1;35m悄然消失。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
