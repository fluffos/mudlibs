// doufu.c 麻婆豆腐

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "麻婆豆腐" NOR, ({"doufu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "在雪白细嫩的豆腐上、点缀着棕红色的牛肉末和油绿的青蒜苗，
外围一圈透亮的红油，如玉镶琥珀，具有麻、辣、烫、嫩、酥、香、鲜的独特风味。\n");
		set("unit", "碗");
		set("value", 60);
		set("food_remaining", 3);
		set("food_supply", 50);
	}
}