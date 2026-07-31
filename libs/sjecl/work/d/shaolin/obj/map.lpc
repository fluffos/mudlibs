#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( HIC "『少林旅游图』" NOR, ({ "shaolin lvyoutu", "tu" }) );
	set_weight(2);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
                set("long", "一张少林旅游图，可以查看(show)少林概貌。\n");
		set("value", 50);
		set("material", "paper");
		set("map", "shaolin");
	}
	setup();
}
void init()
{
	add_action("show_map","show");
}

int show_map(string arg)
{
	if (arg != "shaolin lvyoutu" && arg != "lvyoutu")
		return notify_fail("你要查看什么？\n");
	write(read_file("/help/map/shaolin"));
	return 1;
}
