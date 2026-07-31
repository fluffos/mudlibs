// cdiamond.c 钻石碎粒

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIW "钻石碎粒" NOR, ({ "chipped diamond" }) );
	set_weight(25);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIW "一粒精光闪闪的如米粒般大小"
                    "的钻石碎粒。\n" NOR);
                set("value", 2000);
		set("unit", "粒");
                set("armor_prop/percao", 13);
set("armor_prop/karay",13);
set("armor_prop/armor", 63);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
	}
        setup();
}


