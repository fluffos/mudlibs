// /clone/drug/huoxiang.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"藿香"NOR, ({"huo xiang"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "株");
                set("value", 3000);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}
