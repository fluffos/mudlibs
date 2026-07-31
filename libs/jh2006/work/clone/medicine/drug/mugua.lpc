// /clone/drug/mugua.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("木瓜", ({"mu gua"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value", 6500);
                set("medicine", "drug");
                set("make/drug", 1);
        }
        setup();
}