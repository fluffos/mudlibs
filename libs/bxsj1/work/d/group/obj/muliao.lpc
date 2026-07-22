// shiliao.c
// by augx@sj  3/15/2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"木料"NOR, ({ "mu liao","liao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块用来修建房屋的木料。\n");
		set("value", 2000000);
		set("no_sell", 1);
		set("group", 1);
	}
	setup();
}
