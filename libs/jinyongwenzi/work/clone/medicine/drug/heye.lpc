// /clone/drug/heye.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"荷叶"NOR, ({"he ye"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "片");
                set("value", 1500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
