// shiliao.c
// by augx@sj  3/15/2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"石料"NOR, ({ "shi liao","liao" }));
	set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是一块用来修建道路的石料。\n");
		set("value", 5000000);
		set("no_sell", 1);
		set("group", 1);
	}
	setup();
}
