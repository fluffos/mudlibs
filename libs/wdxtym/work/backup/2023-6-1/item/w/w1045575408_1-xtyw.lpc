// ITEM Made by player(龙飞辰:w1045575408_1) /data/item/w/w1045575408_1-xtyw.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 05:33:19 2023
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("玄铁一握[2;37;0m", ({ "xtyw" }));
	set_weight(2250);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[37m上古寒铁[2;37;0m炼制而成的一双铁掌。
由深海玄铁制造，注入内力炼制而成[2;37;0m
铁掌缘上刻着一行小字：龙飞辰(w1045575408_1)
");
	set("value", 1500000);
	set("point", 154);
	set("material", "steel");
	set("wear_msg", "只见寒光一闪，冷冽的拳套就已经戴在了手上[2;37;0m\n");
	set("remove_msg", "$N轻轻一握，寒光照铁衣[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
