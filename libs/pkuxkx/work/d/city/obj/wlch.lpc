// hook.c

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("乌龙茶", ({ "wulong cha", "tea" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "包");
                set("long", "这是一包乌龙茶，据说是南方很流行的一种茶叶。\n");
		set("value", 10000);
		set("material", "tea");
             }
       setup();
}
