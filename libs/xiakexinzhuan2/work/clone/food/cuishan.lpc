// cuishan.c  梁溪脆鳝

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "梁溪脆鳝" NOR, ({"liangxi cuishan", "cuishan"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "梁溪脆鳝形如一座造型优美的山，错落有致，色呈酱褐，乌光油亮，
脆能嚼断数截，松则满口消融，甜中有咸，葱姜溢香。\n");
		set("unit", "盘");
		set("value", 200);
		set("food_remaining", 2);
		set("food_supply", 35);
	}
}