#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"银盘"NOR, ({ "yin pan", "pan" }));
        set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
                set("long", "一只银盘。\n");
                set("value", 3000);
		set("material", "silver");
	}
	setup();
}
