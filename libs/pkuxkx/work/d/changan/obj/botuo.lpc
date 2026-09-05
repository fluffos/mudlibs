// jitui.c 鸡腿
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"餺飥"NOR, ({ "bo tuo", "bing" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "薄片形状的面皮，水煮而成，又称汤饼。\n");
		set("unit", "碗");
    set("value", 200);
		set("food_remaining", 8);
    set("food_supply", 25);
	}
	setup();
}