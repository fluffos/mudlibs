
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name( "鲤鱼", ({ "yu" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "尾");
		set("value", 100);
	}
	setup();
}
