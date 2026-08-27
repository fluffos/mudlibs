// dart.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("飛鏢", ({ "dart" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"飛鏢是一種十分常見的暗器。\n");
		set("unit", "些");
		set("base_unit", "枝");
		set("base_weight", 40);
		set("base_value", 5);
	}
	set_amount(1);
	init_throwing(20);
	setup();
}
