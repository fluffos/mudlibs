// kaoya.c 烤鸭
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIM"糖醋鲤鱼"NOR, ({"tangcu liyu", "liyu"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盘色味俱全的糖醋鲤鱼。\n");
		set("unit", "盘");
		set("value", 700);
		set("food_remaining", 4);
		set("food_supply", 10);
	}
}
