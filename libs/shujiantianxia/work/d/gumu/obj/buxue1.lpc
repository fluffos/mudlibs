// buxue1.c   布靴
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( HIW "白布靴" NOR, ({ "bai buxue", "buxue", "shoe" }) );
	set_weight(150);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", "一双白布面料制成的靴子。\n");
		set("value", 0);
		set("material", "boots");
		set("armor_prop/dodge", 2);		
	}
	setup();
}
