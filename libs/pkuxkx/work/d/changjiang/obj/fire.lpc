// Zine 2012,射雕主线quest物品

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("火堆", ({ "huo dui","dui"}));
	set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一堆燃着的柴火。\n");
			set("unit", "堆");
		}
	set("value",0);
	set("is__fire",1);
	set("no_get","你要把火堆捡起来？\n");
	setup();
	call_out("unfire",360);
}
int unfire()
{
	message_vision(RED"$N火势突然变急，然后就告熄灭了。\n"NOR,this_object());
	destruct(this_object());
	return 1;
}

