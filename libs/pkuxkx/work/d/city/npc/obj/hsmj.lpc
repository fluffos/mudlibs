// hook.c

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("黄山毛尖", ({ "huangshan maojian", "tea" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "包");
                set("long", "这是著名的黄山毛尖，是毛尖中的极品\n");
		set("value", 10000);
		set("material", "tea");
             }
       setup();
}
