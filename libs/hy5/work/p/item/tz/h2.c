// cagate.c 玛瑙残片

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIR "玛瑙残片" NOR, ({ "chipped agate" }) );
	set_weight(25);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIR "一片的玛瑙碎片，发出微弱的红光。\n" NOR);
                set("value", 2000);
		set("unit", "片");set("no_get",1); set("no_put",1);set("no_pawn",1);set("no_drop",1);set("no_beg",1);set("no_steal",1);set("systemmake",1);
                set("armor_prop/percao", 13);
                set("armor_prop/karay",13);
set("armor_prop/armor", 163);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
	}
        setup();
}


