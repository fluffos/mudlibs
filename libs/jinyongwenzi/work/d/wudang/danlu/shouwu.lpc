#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(GRN"何首乌"NOR, ({"he shouwu"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value", 3000);
                set("medicine", "drug");
                set("make/drug", 1);
        }
        setup();
}
