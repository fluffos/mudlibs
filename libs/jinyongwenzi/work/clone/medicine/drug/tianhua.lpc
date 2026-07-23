// /clone/drug/tianhua.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"天花粉"NOR, ({"tianhua fen"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "包");
                set("value", 1500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
