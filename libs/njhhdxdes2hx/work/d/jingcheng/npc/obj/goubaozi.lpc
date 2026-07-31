// kaoya.c 烤鸭
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("狗不理包子"NOR, ({"goubuli baozi", "baozi"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个热气腾腾的包子。\n");
		set("unit", "个");
		set("value", 300);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
