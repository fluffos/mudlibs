#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( HIC "『襄阳地图册』" NOR, ({ "xiangyang dituce", "dituce", "tuce", "map" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long", "一本线装的地图册，可以查看(show)襄阳的大致情况。\n");
		set("value", 50);
		set("material", "paper");
	}
	setup();
}
void init()
{
	add_action("show_map","show");
}

int show_map()
{
	write(read_file("/help/map/xiangyang"));
	return 1;
}
