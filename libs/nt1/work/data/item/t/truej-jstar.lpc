// SN:QWmj<:806EO\IUXk
// ITEM Made by player(邢全:truej) /data/item/t/truej-jstar.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Nov 28 21:19:41 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m全[1;37m之[1;33m星[2;37;0m", ({ "jstar" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
煞气逼人的凶星[1;31m全[1;37m之[1;33m星[2;37;0m
铁掌缘上刻着一行小字：邢全(truej)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "magic stone");
	set("wear_msg", "一道星光从天空直落而下，[1;31m全[1;37m之[1;33m星[2;37;0m，融入手掌[2;37;0m\n");
	set("remove_msg", "[1;33m金光[2;37;0m直入天际，[1;31m全[1;37m之[1;33m星[2;37;0m倏然消失[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
