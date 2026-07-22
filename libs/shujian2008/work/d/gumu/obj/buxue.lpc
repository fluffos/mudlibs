// buxue.c   布靴
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( HIC "青布靴" NOR, ({ "qing buxue", "xue", "shoe" }) );
	set_weight(120);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", "一双青布面料制成的靴子。\n");
		set("value", 0);
		set("material", "boots");
		set("armor_prop/dodge", 1);		
	}
	setup();
}
