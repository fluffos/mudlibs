// hook.c

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("西湖龙井", ({ "xihu longjing", "tea" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "包");
                set("long", "这是著名的西湖龙井，产自临安府，闻起来有一种淡淡的清香\n");
		set("value", 10000);
		set("material", "tea");
             }
       setup();
}
