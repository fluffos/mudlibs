// /clone/drug/hugu.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"虎骨"NOR, ({"hu gu", "gu"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 1500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
