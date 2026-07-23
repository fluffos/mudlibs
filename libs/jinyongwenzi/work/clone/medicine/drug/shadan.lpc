// /clone/drug/shadan.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"鲨胆"NOR, ({"sha dan"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value", 11500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
