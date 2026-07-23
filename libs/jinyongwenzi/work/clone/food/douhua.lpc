// douhua.c 鸡豆花

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "鸡豆花" NOR, ({"douhua"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "鸡豆花色白细嫩，汤清味鲜，源于豆花，高于豆花，
被誉名为“豆花不用豆，吃鸡不见鸡”的佳肴美馔。\n");
		set("unit", "碗");
		set("value", 120);
		set("food_remaining", 1);
		set("food_supply", 30);
	}
}