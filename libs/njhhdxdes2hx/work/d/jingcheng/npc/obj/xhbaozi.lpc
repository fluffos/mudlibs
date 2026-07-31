// kaoya.c 烤鸭
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"蟹黄包子"NOR, ({"xiehuang baozi", "baozi"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个热气腾腾的包子。\n");
		set("unit", "个");
		set("value", 200);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
}
