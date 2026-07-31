// fjade.c 稀世翡翠

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIG "稀世翡翠" NOR, ({ "flawless jade" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIG "一块美得无与伦比的大翡翠。"NOR"\n");
		set("base_value", 100000);
		set("base_weight", 1);
		set("base_unit", "块");
		set("can_be_enchased", __DIR__"mjade");
		set("enchased_need", 3);
		set("magic/type", "cold");
		set("magic/power", 125);
	}
	set_amount(1);
	setup();
}
