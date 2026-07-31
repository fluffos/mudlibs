// agate.c 玛瑙

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIR "玛瑙" NOR, ({ "agate" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
        else {
	        set("long", HIR "一块晶莹剔透的暗红色玛瑙。\n" NOR);
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


