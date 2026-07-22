// dart.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("飞刀", ({ "fei dao","feidao","dart" ,"dao"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"这是由精钢打造的十分精巧的飞刀。\n");
		set("unit", "些");
		set("base_unit", "柄");
		set("base_weight", 40);
		set("base_value", 10);
		set("material", "gang");
		set("value", 10);
	}
	set_amount(1);
	init_throwing(20);
	setup();
}
