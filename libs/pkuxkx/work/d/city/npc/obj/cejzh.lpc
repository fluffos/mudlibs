// hook.c

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(YEL"侧金盏"NOR, ({ "cejinzhan", "hua" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "盆");
                set("long", "这盆花的花朵就象一个个金色的小灯笼分布在花的一侧。\n");
		set("value", 2000);
		set("material", "wood");
             }
       setup();
}
