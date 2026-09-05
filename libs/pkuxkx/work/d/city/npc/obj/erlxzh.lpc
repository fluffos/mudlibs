// hook.c

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("二龙戏珠", ({ "erlong xizhu", "tea" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "包");
                set("long", "这是花茶的极品，茶叶如同一个个小圆球，故得此名\n");
		set("value", 10000);
		set("material", "tea");
             }
       setup();
}
