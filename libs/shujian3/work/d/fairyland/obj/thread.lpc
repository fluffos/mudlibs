// thread.c
// By jpei
// Modify By River@SJ

#include <ansi.h>
inherit COMBINED_ITEM;
void create()
{
	set_name(HIW"细丝"NOR, ({ "xi si", "thread", "si" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是由树皮搓成的细丝。\n");
		set("material", "wood");
                set("base_unit", "根");
                set("base_weight", 100);
	}
        set_amount(1);
	setup();
}
