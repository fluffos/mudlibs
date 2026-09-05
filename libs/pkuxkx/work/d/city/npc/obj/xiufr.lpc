// hook.c

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIY"绣芙蓉"NOR, ({ "xiufu rong", "hua" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "盆");
                set("long", "虽然这是一盆菊花，但花朵的形状就象是南国的芙蓉\n");
		set("value", 2000);
		set("material", "wood");
             }
       setup();
}
