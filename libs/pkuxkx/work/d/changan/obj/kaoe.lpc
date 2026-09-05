// jitui.c 鸡腿
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"浑羊殁忽"NOR, ({ "hunyang mohu", "kaoe" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "浑羊殁忽是从西域传过来一道名菜，做法是将子鹅洗干净，填充肉和糯米饭，\n调好料放入洗净羊腹中缝合，灸烤熟了舍羊取鹅浑食之。\n");
		set("unit", "只");
    set("value", 5000);
		set("food_remaining", 25);
    set("food_supply", 100);
	}
	setup();
}