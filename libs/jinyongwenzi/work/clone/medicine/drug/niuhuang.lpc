// /clone/drug/niuhuang.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"牛黄"NOR, ({"niu huang"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value", 2000);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
