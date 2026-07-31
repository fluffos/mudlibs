// shoe.c
//by steel
#include "armor.h"
#include "ansi.h"

inherit BOOTS;

void create()
{
	set_name(HIR "闯王战靴" NOR, ({ "cw_boots", "boots"}) );
       	set("long", "这是一双李闯王穿过的战靴,做工极其精致。\n");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "wood");
		set("unit", "双");
		set("no_put", 1);
//		//set("value", 100000);
		set("armor_prop/armor",150);
		set("armor_prop/attack", 10);
	}
	setup();
}
