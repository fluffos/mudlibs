// hook.c

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(RED"美人红"NOR, ({ "meiren hong", "hua" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "盆");
                set("long", "这是一盆菊花，开着几朵粉红色的花朵，就象美女们的脸那么迷人\n");
		set("value", 2000);
		set("material", "wood");
             }
       setup();
}
