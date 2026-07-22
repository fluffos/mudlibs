
#include <ansi.h>

inherit ITEM;

 void create()
{
        set_name(YEL "大木头" NOR, ({"mu tou", "mu"}));
        set_weight(200000);
        set("no_get",1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "一些");
                set("long", "这是几根大木头，也不知道干嘛用。\n");
        }

        setup();
}
