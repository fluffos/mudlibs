// yaoliu.c 番茄腰柳

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "番茄腰柳" NOR, ({"fanqie yaoliu", "yaoliu"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "番茄腰柳的特点是肉质软嫩，味道甜酸，汁为红色。\n因猪里脊肉位于腰部，扁而细长呈柳叶状，故俗称腰柳。\n");
		set("unit", "碗");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
}