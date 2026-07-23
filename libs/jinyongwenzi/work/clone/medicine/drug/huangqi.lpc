// /clone/drug/huangqi.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"黄芪"NOR, ({"huang qi"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "株");
                set("value", 2500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
