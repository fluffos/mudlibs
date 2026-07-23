// maotan.c 毛毯

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"绣花密织毯"NOR, ({"mao tan", "maotan"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "
            这是一张手工编织的纯毛毯，毯毛细密厚实，摸上去非常柔软，\n
            可以挂在墙壁或铺在地板上。\n");
                set("unit", "张");
                set("value", 50000);
        }
}
