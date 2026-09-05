#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name(RED"蜜桃"NOR,({"mitao"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("long","一个又红又大的蜜桃。\n");
		set("unit","个");
		set("value",100);
		set("food_remaining",5);
		set("food_supply",30);
	}
}
