// crystal.c 水晶

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIM "水晶" NOR, ({ "crystal" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
        else {
	        set("long", HIM "一块粉色的水晶。\n" NOR);
                set("value", 5000);
		set("unit", "块");
                set("armor_prop/percao", 15);
set("armor_prop/karay",15);
set("armor_prop/armor", 65);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
	}
        setup();
}


