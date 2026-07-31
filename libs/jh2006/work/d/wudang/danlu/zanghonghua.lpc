#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"藏红花"NOR, ({"zang honghua"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value", 9000);
                set("medicine", "drug");
                set("make/drug", 1);
        }
        setup();
}