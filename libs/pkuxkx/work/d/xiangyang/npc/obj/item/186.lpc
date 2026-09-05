// hook.c

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("铁观音", ({ "tie guanyin", "tea" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "包");
                set("long", "这是一包铁观音，一包在手，茶香四溢，真可以算是好茶\n");
		set("value", 10000);
		set("material", "tea");
             }
       setup();
}
