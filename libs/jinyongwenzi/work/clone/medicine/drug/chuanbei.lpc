// /clone/drug/chuanbei.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"川贝"NOR, ({"chuan bei"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 4500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
