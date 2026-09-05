// icy_cloth.c

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name( "钓鱼杆", ({ "yugan" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("value", 0);
	}
	setup();
}
