// hook.c

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("菊花茶", ({ "juhua cha", "tea" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "包");
                set("long", "这是一包菊花茶，它是菊花和茶叶精制而成，具有清热消暑的功效\n");
		set("value", 10000);
		set("material", "tea");
             }
       setup();
}
