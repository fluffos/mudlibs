// /clone/drug/tianqi.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"田七"NOR, ({"tian qi"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value", 2500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
