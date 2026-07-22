// shihui.c
// by augx@sj  3/15/2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"石灰"NOR, ({ "shi hui","hui" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块用来粉刷房间的石灰。\n");
		set("value", 1500000);
		set("no_sell", 1);
		set("group", 1);
	}
	setup();
}
