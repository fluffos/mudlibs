
#include <ansi.h>

inherit ITEM;
void create()
{
	set_name("石块", ({ "shikuai", "shi kuai", "shi", "stone" }));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
		{
			set("long", "一块大石头，不知道有什么用。\n");
			set("unit", "块");
			set("value", 0);
		}
	setup();
}

